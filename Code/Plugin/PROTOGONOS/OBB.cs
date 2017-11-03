using UnityEngine;
using System.Collections;


/// <summary>
/// Oriented bounding box
/// </summary>
public class OBB
{
    /// <summary>
    /// 在可能的分离轴（每个OBB的四个面法线）上的投影
    /// </summary>
    class Projection  
    {
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="min"></param>
        /// <param name="max"></param>
        public Projection(float min, float max)
        {
            this.min = min;
            this.max = max;
        }
  
        /// <summary>
        /// 两个投影是否重叠
        /// </summary>
        /// <param name="proj"></param>
        /// <param name="epsilon"></param>
        /// <returns></returns>
        public bool Overlap(Projection proj, float epsilon)
        {
            if (min > proj.max - epsilon) return false;
            if (max < proj.min + epsilon) return false;

            return true; 
        }

        public float min;
        public float max;
    }

    private Vector2[] corners = new Vector2[4];

    /// <summary>
    /// 使用AABB构造
    /// </summary>
    /// <param name="c"></param>
    public OBB(BoxCollider c)
    {
        Vector3[] corners = new Vector3[4];

        // 取得四个角的坐标
        corners[0].Set(c.center.x - c.size.x * 0.5f, 0.0f, c.center.z - c.size.z * 0.5f);
        corners[1].Set(c.center.x - c.size.x * 0.5f, 0.0f, c.center.z + c.size.z * 0.5f);
        corners[2].Set(c.center.x + c.size.x * 0.5f, 0.0f, c.center.z + c.size.z * 0.5f);
        corners[3].Set(c.center.x + c.size.x * 0.5f, 0.0f, c.center.z - c.size.z * 0.5f);

        // 运用本地旋转
        corners[0] = c.transform.rotation * corners[0];
        corners[1] = c.transform.rotation * corners[1];
        corners[2] = c.transform.rotation * corners[2];
        corners[3] = c.transform.rotation * corners[3];

        // 移动到世界坐标系
        corners[0] += c.transform.position;
        corners[1] += c.transform.position;
        corners[2] += c.transform.position;
        corners[3] += c.transform.position;

        this.corners[0].Set(corners[0].x, corners[0].z);
        this.corners[1].Set(corners[1].x, corners[1].z);
        this.corners[2].Set(corners[2].x, corners[2].z);
        this.corners[3].Set(corners[3].x, corners[3].z);
    }

    /// <summary>
    /// 使用四个点构造
    /// </summary>
    /// <param name="corners"></param>
    public OBB(Vector2[] corners)
    {
        this.corners[0] = corners[0];
        this.corners[1] = corners[1];
        this.corners[2] = corners[2];
        this.corners[3] = corners[3];
    }

    /// <summary>
    /// 检查与另一个OBB是否碰撞
    /// </summary>
    /// <param name="obb"></param>
    /// <returns></returns>
    public bool IsCollidWithOBB(OBB obb, float epsilon)
    {
        Vector2[] axies1 = new Vector2[4];
        Vector2[] axies2 = new Vector2[4];

        // 获得分离轴
        GetAxies(axies1);
        obb.GetAxies(axies2);

        // 检查所有轴上的投影是否重叠，只有全部重叠的时候才会发生碰撞  
        for (int i = 0; i < 4; ++i)
        {
            Projection p1 = GetProjection(axies1[i]);
            Projection p2 = obb.GetProjection(axies1[i]);

            if (!p1.Overlap(p2, epsilon))
                return false;
        }
        for (int i = 0; i < 4; ++i)
        {
            Projection p1 = GetProjection(axies2[i]);
            Projection p2 = obb.GetProjection(axies2[i]);

            if (!p1.Overlap(p2, epsilon))
                return false;
        }

        return true;
    }  

    /// <summary>
    /// 获得可能的分离轴，四个2D平面的法向量
    /// </summary>
    /// <param name="axies"></param>
    void GetAxies(Vector2[] axies)  
    {  
        for (int i = 0; i < 4; ++i)  
        {
            Vector2 s = corners[i] - corners[(i + 1) % 4];
            s.Normalize();
            // 2D向量的法向量，交换XY，其中任意一个取负
            axies[i].x = -s.y;
            axies[i].y = s.x;
        }  
    }

    /// <summary>
    /// 获得在轴上的投影（点积）
    /// </summary>
    /// <param name="axis"></param>
    /// <returns></returns>
    Projection GetProjection(Vector2 axis)
    {
        float min = Vector2.Dot(corners[0], axis);
        float max = min;

        for (int i = 1; i < 4; ++i)
        {
            float temp = Vector2.Dot(corners[i], axis);
            if (temp > max)
                max = temp;
            else if (temp < min)
                min = temp;
        }

        return new Projection(min, max);
    }  
}

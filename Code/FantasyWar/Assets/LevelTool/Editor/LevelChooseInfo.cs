using UnityEngine;
using System.Collections;
using UnityEditor;


public class LevelChooseInfo : Editor
{
    public static bool isVisible = true;
    [DrawGizmo(GizmoType.InSelectionHierarchy | GizmoType.NotInSelectionHierarchy )]
    static void DrawGameObjectName(Transform transform, GizmoType gizmoType)
    {
        if (transform)
        {
            LevelObjectBase m = transform.GetComponentInChildren<LevelObjectBase>();
            if (m)
            {
                if (isVisible && m.GetData().isVisible)
                {
                    GUIStyle style = new GUIStyle();
                    style.richText = true;
                    Handles.Label(transform.position, string.Format("<size={0}><color={1}>{2}</color></size>", m.GetData().fontSize,
                        string.Format("#{0:X2}{1:X2}{2:X2}{3:X2}", m.GetData().nameColor.r, m.GetData().nameColor.g, m.GetData().nameColor.b, m.GetData().nameColor.a),
                        m.GetGizmoName()), style);
                }

                if (m is LevelArea)
                {
                    LevelAreaData data = m.GetData() as LevelAreaData;
                    if (LevelTool.showArea && data.isVisible)
                    {
                        switch (data.type)
                        {
                            case LevelAreaData.Type.Base:
                                Handles.color = Color.green;
                                break;
                            case LevelAreaData.Type.Defend:
                                Handles.color = Color.red;
                                break;
                            case LevelAreaData.Type.Normal:
                                Handles.color = Color.blue;
                                break;
                        }
                        DrawCircle(m.transform.position, data.radius);
                    }
                }
            }
        }

    }

    public static void DrawCircle(Vector3 center,float radius)
    {
        BetterList<Vector3> points = new BetterList<Vector3>();
       
        for (int i = 0; i < 100 * 2 * 3.14; i++)
        {
            Vector3 v = new Vector3();
            v = center;

            v.x += Mathf.Cos((float)i / 100) * radius;
            v.z += Mathf.Sin((float)i / 100) * radius;

            points.Add(v);
        }

        
        
        Handles.DrawPolyLine(points.ToArray());
    }
}

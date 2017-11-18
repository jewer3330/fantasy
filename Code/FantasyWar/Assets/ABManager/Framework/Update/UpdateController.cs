using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using SuperBoBo;
using UnityEngine.UI;

public class UpdateEvent
{
    public const string Updater_ApkFirstStart = "1";
    public const string Updater_ApkNormalStart = "2";
    public const string Updater_DownloadVersionListDone = "3";
    public const string Updater_CompareVersion = "4";
    public const string Updater_DownloadMD2Done = "5";
    public const string Updater_UpdateDone = "6";
    public const string Updater_DownloadMDDone = "7";
    public const string Updater_DownloadUpdateTipDone = "8";
  

}

public class UpdateController : MonoBehaviour {

    public List<Action> actions = new List<Action>();
    public GameUpdater updater;

    public Text text;


    ActionFuncTimeOut downResVersionListAction;
    ActionFuncTimeOut compareVersionAction;
    ActionFuncTimeOut downMD2Action;
    ActionFuncTimeOut downMDAction;
    ActionFuncTimeOut downTipAction;



    void Awake()
    {
        EventManager.Instance.Reg(UpdateEvent.Updater_ApkFirstStart, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_ApkNormalStart, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_DownloadVersionListDone, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_CompareVersion, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_DownloadMD2Done, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_UpdateDone, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_DownloadMDDone, UpdaterHandle);
        EventManager.Instance.Reg(UpdateEvent.Updater_DownloadUpdateTipDone, UpdaterHandle);


        //UIMessageBoxHelper.onCancel = UIMessageBox.OnCancel;
        //UIMessageBoxHelper.onShow0 = UIMessageBox.Show;
        //UIMessageBoxHelper.onShow1 = UIMessageBox.Show;
        //UIMessageBoxHelper.onShow3 = UIMessageBox.Show;
        //UIMessageBoxHelper.onShowUpdate = UIMessageBox.ShowUpdate;

        

    }

	// Use this for initialization
	void Start () {
        

        updater = gameObject.AddComponent<GameUpdater>();
        updater.CheckIsFirstStart();
        downResVersionListAction = new ActionFuncTimeOut(updater.DownloadResVersionList, 5f, IgnoreVersion);
        compareVersionAction = new ActionFuncTimeOut(updater.CompareVersion, 5f, TimeOut);
        downMD2Action = new ActionFuncTimeOut(updater.DownloadMD2File, 5f, TimeOut);
        downMDAction = new ActionFuncTimeOut(updater.DownloadMD, 5, TimeOut);
        downTipAction = new ActionFuncTimeOut(updater.DownLoadTips, 5, TimeOut);

        Timer.Instance.Run(downResVersionListAction);
	}

    private void IgnoreVersion(float delta)
    {
        StartCoroutine(StartGame());
    }

    private IEnumerator StartGame()
    {
        yield return AssetManifest.Init();
        ABsManager.m_AssetBundleManifest = AssetManifest.manifest;
        ResManager.Instance.m_pattern = ResManager.Pattern.AssetBundle;
        ResManager.LoadLevel("Launch");
    }

    private void TimeOut(float delta)
    {
        Debug.Log("time out " + delta);
    }
	
	// Update is called once per frame
	void Update () {
        Timer.Instance.Update();
        text.text = updater.tip;
	}

    void UpdaterHandle(string e, object[] args)
    {
        switch (e)
        {
            default: 
                break;
            case UpdateEvent.Updater_ApkFirstStart:
                Debug.Log("first start");
                break;
            case UpdateEvent.Updater_ApkNormalStart:
                Debug.Log("normal start");
                break;
            case UpdateEvent.Updater_DownloadVersionListDone:
                Debug.Log("download resVersionlist");
                Timer.Instance.Stop();
                Timer.Instance.Run(compareVersionAction);
                break;
            case UpdateEvent.Updater_CompareVersion:
                Debug.Log("download md2");
                Timer.Instance.Stop();
                Timer.Instance.Run(downMD2Action);
                break;
            case UpdateEvent.Updater_DownloadMD2Done:
                Debug.Log("download md");
                Timer.Instance.Stop();
                Timer.Instance.Run(downMDAction);
                break;
            case UpdateEvent.Updater_DownloadMDDone:
                Debug.Log("download tip");
                Timer.Instance.Stop();
                Timer.Instance.Run(downTipAction);                
                break;
            case UpdateEvent.Updater_UpdateDone:
                Timer.Instance.Stop();
                Debug.Log("update done");
                StartCoroutine(StartGame());
                break;
            case UpdateEvent.Updater_DownloadUpdateTipDone:
                Debug.Log("show tip & update");
                Timer.Instance.Stop();
                updater.ShowUpdateTip();
                break;
        }
    }

}

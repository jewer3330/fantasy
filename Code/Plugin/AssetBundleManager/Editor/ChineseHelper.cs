using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

/// <summary>
/// 获得汉字的拼音
/// </summary>
static public class ChineseHelper
{
    static private Hashtable _pinyinHash;

    #region static stor.
    static ChineseHelper()
    {
        _pinyinHash = new Hashtable();
        _pinyinHash.Add(-20319, "a");
        _pinyinHash.Add(-20317, "ai"); _pinyinHash.Add(-20304, "an"); _pinyinHash.Add(-20295, "ang");
        _pinyinHash.Add(-20292, "ao"); _pinyinHash.Add(-20283, "ba"); _pinyinHash.Add(-20265, "bai");
        _pinyinHash.Add(-20257, "ban"); _pinyinHash.Add(-20242, "bang"); _pinyinHash.Add(-20230, "bao");
        _pinyinHash.Add(-20051, "bei"); _pinyinHash.Add(-20036, "ben"); _pinyinHash.Add(-20032, "beng");
        _pinyinHash.Add(-20026, "bi"); _pinyinHash.Add(-20002, "bian"); _pinyinHash.Add(-19990, "biao");
        _pinyinHash.Add(-19986, "bie"); _pinyinHash.Add(-19982, "bin"); _pinyinHash.Add(-19976, "bing");
        _pinyinHash.Add(-19805, "bo"); _pinyinHash.Add(-19784, "bu"); _pinyinHash.Add(-19775, "ca");
        _pinyinHash.Add(-19774, "cai"); _pinyinHash.Add(-19763, "can"); _pinyinHash.Add(-19756, "cang");
        _pinyinHash.Add(-19751, "cao"); _pinyinHash.Add(-19746, "ce"); _pinyinHash.Add(-19741, "ceng");
        _pinyinHash.Add(-19739, "cha"); _pinyinHash.Add(-19728, "chai"); _pinyinHash.Add(-19725, "chan");
        _pinyinHash.Add(-19715, "chang"); _pinyinHash.Add(-19540, "chao"); _pinyinHash.Add(-19531, "che");
        _pinyinHash.Add(-19525, "chen"); _pinyinHash.Add(-19515, "cheng"); _pinyinHash.Add(-19500, "chi");
        _pinyinHash.Add(-19484, "chong"); _pinyinHash.Add(-19479, "chou"); _pinyinHash.Add(-19467, "chu");
        _pinyinHash.Add(-19289, "chuai"); _pinyinHash.Add(-19288, "chuan"); _pinyinHash.Add(-19281, "chuang");
        _pinyinHash.Add(-19275, "chui"); _pinyinHash.Add(-19270, "chun"); _pinyinHash.Add(-19263, "chuo");
        _pinyinHash.Add(-19261, "ci"); _pinyinHash.Add(-19249, "cong"); _pinyinHash.Add(-19243, "cou");
        _pinyinHash.Add(-19242, "cu"); _pinyinHash.Add(-19238, "cuan"); _pinyinHash.Add(-19235, "cui");
        _pinyinHash.Add(-19227, "cun"); _pinyinHash.Add(-19224, "cuo"); _pinyinHash.Add(-19218, "da");
        _pinyinHash.Add(-19212, "dai"); _pinyinHash.Add(-19038, "dan"); _pinyinHash.Add(-19023, "dang");
        _pinyinHash.Add(-19018, "dao"); _pinyinHash.Add(-19006, "de"); _pinyinHash.Add(-19003, "deng");
        _pinyinHash.Add(-18996, "di"); _pinyinHash.Add(-18977, "dian"); _pinyinHash.Add(-18961, "diao");
        _pinyinHash.Add(-18952, "die"); _pinyinHash.Add(-18783, "ding"); _pinyinHash.Add(-18774, "diu");
        _pinyinHash.Add(-18773, "dong"); _pinyinHash.Add(-18763, "dou"); _pinyinHash.Add(-18756, "du");
        _pinyinHash.Add(-18741, "duan"); _pinyinHash.Add(-18735, "dui"); _pinyinHash.Add(-18731, "dun");
        _pinyinHash.Add(-18722, "duo"); _pinyinHash.Add(-18710, "e"); _pinyinHash.Add(-18697, "en");
        _pinyinHash.Add(-18696, "er"); _pinyinHash.Add(-18526, "fa"); _pinyinHash.Add(-18518, "fan");
        _pinyinHash.Add(-18501, "fang"); _pinyinHash.Add(-18490, "fei"); _pinyinHash.Add(-18478, "fen");
        _pinyinHash.Add(-18463, "feng"); _pinyinHash.Add(-18448, "fo"); _pinyinHash.Add(-18447, "fou");
        _pinyinHash.Add(-18446, "fu"); _pinyinHash.Add(-18239, "ga"); _pinyinHash.Add(-18237, "gai");
        _pinyinHash.Add(-18231, "gan"); _pinyinHash.Add(-18220, "gang"); _pinyinHash.Add(-18211, "gao");
        _pinyinHash.Add(-18201, "ge"); _pinyinHash.Add(-18184, "gei"); _pinyinHash.Add(-18183, "gen");
        _pinyinHash.Add(-18181, "geng"); _pinyinHash.Add(-18012, "gong"); _pinyinHash.Add(-17997, "gou");
        _pinyinHash.Add(-17988, "gu"); _pinyinHash.Add(-17970, "gua"); _pinyinHash.Add(-17964, "guai");
        _pinyinHash.Add(-17961, "guan"); _pinyinHash.Add(-17950, "guang"); _pinyinHash.Add(-17947, "gui");
        _pinyinHash.Add(-17931, "gun"); _pinyinHash.Add(-17928, "guo"); _pinyinHash.Add(-17922, "ha");
        _pinyinHash.Add(-17759, "hai"); _pinyinHash.Add(-17752, "han"); _pinyinHash.Add(-17733, "hang");
        _pinyinHash.Add(-17730, "hao"); _pinyinHash.Add(-17721, "he"); _pinyinHash.Add(-17703, "hei");
        _pinyinHash.Add(-17701, "hen"); _pinyinHash.Add(-17697, "heng"); _pinyinHash.Add(-17692, "hong");
        _pinyinHash.Add(-17683, "hou"); _pinyinHash.Add(-17676, "hu"); _pinyinHash.Add(-17496, "hua");
        _pinyinHash.Add(-17487, "huai"); _pinyinHash.Add(-17482, "huan"); _pinyinHash.Add(-17468, "huang");
        _pinyinHash.Add(-17454, "hui"); _pinyinHash.Add(-17433, "hun"); _pinyinHash.Add(-17427, "huo");
        _pinyinHash.Add(-17417, "ji"); _pinyinHash.Add(-17202, "jia"); _pinyinHash.Add(-17185, "jian");
        _pinyinHash.Add(-16983, "jiang"); _pinyinHash.Add(-16970, "jiao"); _pinyinHash.Add(-16942, "jie");
        _pinyinHash.Add(-16915, "jin"); _pinyinHash.Add(-16733, "jing"); _pinyinHash.Add(-16708, "jiong");
        _pinyinHash.Add(-16706, "jiu"); _pinyinHash.Add(-16689, "ju"); _pinyinHash.Add(-16664, "juan");
        _pinyinHash.Add(-16657, "jue"); _pinyinHash.Add(-16647, "jun"); _pinyinHash.Add(-16474, "ka");
        _pinyinHash.Add(-16470, "kai"); _pinyinHash.Add(-16465, "kan"); _pinyinHash.Add(-16459, "kang");
        _pinyinHash.Add(-16452, "kao"); _pinyinHash.Add(-16448, "ke"); _pinyinHash.Add(-16433, "ken");
        _pinyinHash.Add(-16429, "keng"); _pinyinHash.Add(-16427, "kong"); _pinyinHash.Add(-16423, "kou");
        _pinyinHash.Add(-16419, "ku"); _pinyinHash.Add(-16412, "kua"); _pinyinHash.Add(-16407, "kuai");
        _pinyinHash.Add(-16403, "kuan"); _pinyinHash.Add(-16401, "kuang"); _pinyinHash.Add(-16393, "kui");
        _pinyinHash.Add(-16220, "kun"); _pinyinHash.Add(-16216, "kuo"); _pinyinHash.Add(-16212, "la");
        _pinyinHash.Add(-16205, "lai"); _pinyinHash.Add(-16202, "lan"); _pinyinHash.Add(-16187, "lang");
        _pinyinHash.Add(-16180, "lao"); _pinyinHash.Add(-16171, "le"); _pinyinHash.Add(-16169, "lei");
        _pinyinHash.Add(-16158, "leng"); _pinyinHash.Add(-16155, "li"); _pinyinHash.Add(-15959, "lia");
        _pinyinHash.Add(-15958, "lian"); _pinyinHash.Add(-15944, "liang"); _pinyinHash.Add(-15933, "liao");
        _pinyinHash.Add(-15920, "lie"); _pinyinHash.Add(-15915, "lin"); _pinyinHash.Add(-15903, "ling");
        _pinyinHash.Add(-15889, "liu"); _pinyinHash.Add(-15878, "long"); _pinyinHash.Add(-15707, "lou");
        _pinyinHash.Add(-15701, "lu"); _pinyinHash.Add(-15681, "lv"); _pinyinHash.Add(-15667, "luan");
        _pinyinHash.Add(-15661, "lue"); _pinyinHash.Add(-15659, "lun"); _pinyinHash.Add(-15652, "luo");
        _pinyinHash.Add(-15640, "ma"); _pinyinHash.Add(-15631, "mai"); _pinyinHash.Add(-15625, "man");
        _pinyinHash.Add(-15454, "mang"); _pinyinHash.Add(-15448, "mao"); _pinyinHash.Add(-15436, "me");
        _pinyinHash.Add(-15435, "mei"); _pinyinHash.Add(-15419, "men"); _pinyinHash.Add(-15416, "meng");
        _pinyinHash.Add(-15408, "mi"); _pinyinHash.Add(-15394, "mian"); _pinyinHash.Add(-15385, "miao");
        _pinyinHash.Add(-15377, "mie"); _pinyinHash.Add(-15375, "min"); _pinyinHash.Add(-15369, "ming");
        _pinyinHash.Add(-15363, "miu"); _pinyinHash.Add(-15362, "mo"); _pinyinHash.Add(-15183, "mou");
        _pinyinHash.Add(-15180, "mu"); _pinyinHash.Add(-15165, "na"); _pinyinHash.Add(-15158, "nai");
        _pinyinHash.Add(-15153, "nan"); _pinyinHash.Add(-15150, "nang"); _pinyinHash.Add(-15149, "nao");
        _pinyinHash.Add(-15144, "ne"); _pinyinHash.Add(-15143, "nei"); _pinyinHash.Add(-15141, "nen");
        _pinyinHash.Add(-15140, "neng"); _pinyinHash.Add(-15139, "ni"); _pinyinHash.Add(-15128, "nian");
        _pinyinHash.Add(-15121, "niang"); _pinyinHash.Add(-15119, "niao"); _pinyinHash.Add(-15117, "nie");
        _pinyinHash.Add(-15110, "nin"); _pinyinHash.Add(-15109, "ning"); _pinyinHash.Add(-14941, "niu");
        _pinyinHash.Add(-14937, "nong"); _pinyinHash.Add(-14933, "nu"); _pinyinHash.Add(-14930, "nv");
        _pinyinHash.Add(-14929, "nuan"); _pinyinHash.Add(-14928, "nue"); _pinyinHash.Add(-14926, "nuo");
        _pinyinHash.Add(-14922, "o"); _pinyinHash.Add(-14921, "ou"); _pinyinHash.Add(-14914, "pa");
        _pinyinHash.Add(-14908, "pai"); _pinyinHash.Add(-14902, "pan"); _pinyinHash.Add(-14894, "pang");
        _pinyinHash.Add(-14889, "pao"); _pinyinHash.Add(-14882, "pei"); _pinyinHash.Add(-14873, "pen");
        _pinyinHash.Add(-14871, "peng"); _pinyinHash.Add(-14857, "pi"); _pinyinHash.Add(-14678, "pian");
        _pinyinHash.Add(-14674, "piao"); _pinyinHash.Add(-14670, "pie"); _pinyinHash.Add(-14668, "pin");
        _pinyinHash.Add(-14663, "ping"); _pinyinHash.Add(-14654, "po"); _pinyinHash.Add(-14645, "pu");
        _pinyinHash.Add(-14630, "qi"); _pinyinHash.Add(-14594, "qia"); _pinyinHash.Add(-14429, "qian");
        _pinyinHash.Add(-14407, "qiang"); _pinyinHash.Add(-14399, "qiao"); _pinyinHash.Add(-14384, "qie");
        _pinyinHash.Add(-14379, "qin"); _pinyinHash.Add(-14368, "qing"); _pinyinHash.Add(-14355, "qiong");
        _pinyinHash.Add(-14353, "qiu"); _pinyinHash.Add(-14345, "qu"); _pinyinHash.Add(-14170, "quan");
        _pinyinHash.Add(-14159, "que"); _pinyinHash.Add(-14151, "qun"); _pinyinHash.Add(-14149, "ran");
        _pinyinHash.Add(-14145, "rang"); _pinyinHash.Add(-14140, "rao"); _pinyinHash.Add(-14137, "re");
        _pinyinHash.Add(-14135, "ren"); _pinyinHash.Add(-14125, "reng"); _pinyinHash.Add(-14123, "ri");
        _pinyinHash.Add(-14122, "rong"); _pinyinHash.Add(-14112, "rou"); _pinyinHash.Add(-14109, "ru");
        _pinyinHash.Add(-14099, "ruan"); _pinyinHash.Add(-14097, "rui"); _pinyinHash.Add(-14094, "run");
        _pinyinHash.Add(-14092, "ruo"); _pinyinHash.Add(-14090, "sa"); _pinyinHash.Add(-14087, "sai");
        _pinyinHash.Add(-14083, "san"); _pinyinHash.Add(-13917, "sang"); _pinyinHash.Add(-13914, "sao");
        _pinyinHash.Add(-13910, "se"); _pinyinHash.Add(-13907, "sen"); _pinyinHash.Add(-13906, "seng");
        _pinyinHash.Add(-13905, "sha"); _pinyinHash.Add(-13896, "shai"); _pinyinHash.Add(-13894, "shan");
        _pinyinHash.Add(-13878, "shang"); _pinyinHash.Add(-13870, "shao"); _pinyinHash.Add(-13859, "she");
        _pinyinHash.Add(-13847, "shen"); _pinyinHash.Add(-13831, "sheng"); _pinyinHash.Add(-13658, "shi");
        _pinyinHash.Add(-13611, "shou"); _pinyinHash.Add(-13601, "shu"); _pinyinHash.Add(-13406, "shua");
        _pinyinHash.Add(-13404, "shuai"); _pinyinHash.Add(-13400, "shuan"); _pinyinHash.Add(-13398, "shuang");
        _pinyinHash.Add(-13395, "shui"); _pinyinHash.Add(-13391, "shun"); _pinyinHash.Add(-13387, "shuo");
        _pinyinHash.Add(-13383, "si"); _pinyinHash.Add(-13367, "song"); _pinyinHash.Add(-13359, "sou");
        _pinyinHash.Add(-13356, "su"); _pinyinHash.Add(-13343, "suan"); _pinyinHash.Add(-13340, "sui");
        _pinyinHash.Add(-13329, "sun"); _pinyinHash.Add(-13326, "suo"); _pinyinHash.Add(-13318, "ta");
        _pinyinHash.Add(-13147, "tai"); _pinyinHash.Add(-13138, "tan"); _pinyinHash.Add(-13120, "tang");
        _pinyinHash.Add(-13107, "tao"); _pinyinHash.Add(-13096, "te"); _pinyinHash.Add(-13095, "teng");
        _pinyinHash.Add(-13091, "ti"); _pinyinHash.Add(-13076, "tian"); _pinyinHash.Add(-13068, "tiao");
        _pinyinHash.Add(-13063, "tie"); _pinyinHash.Add(-13060, "ting"); _pinyinHash.Add(-12888, "tong");
        _pinyinHash.Add(-12875, "tou"); _pinyinHash.Add(-12871, "tu"); _pinyinHash.Add(-12860, "tuan");
        _pinyinHash.Add(-12858, "tui"); _pinyinHash.Add(-12852, "tun"); _pinyinHash.Add(-12849, "tuo");
        _pinyinHash.Add(-12838, "wa"); _pinyinHash.Add(-12831, "wai"); _pinyinHash.Add(-12829, "wan");
        _pinyinHash.Add(-12812, "wang"); _pinyinHash.Add(-12802, "wei"); _pinyinHash.Add(-12607, "wen");
        _pinyinHash.Add(-12597, "weng"); _pinyinHash.Add(-12594, "wo"); _pinyinHash.Add(-12585, "wu");
        _pinyinHash.Add(-12556, "xi"); _pinyinHash.Add(-12359, "xia"); _pinyinHash.Add(-12346, "xian");
        _pinyinHash.Add(-12320, "xiang"); _pinyinHash.Add(-12300, "xiao"); _pinyinHash.Add(-12120, "xie");
        _pinyinHash.Add(-12099, "xin"); _pinyinHash.Add(-12089, "xing"); _pinyinHash.Add(-12074, "xiong");
        _pinyinHash.Add(-12067, "xiu"); _pinyinHash.Add(-12058, "xu"); _pinyinHash.Add(-12039, "xuan");
        _pinyinHash.Add(-11867, "xue"); _pinyinHash.Add(-11861, "xun"); _pinyinHash.Add(-11847, "ya");
        _pinyinHash.Add(-11831, "yan"); _pinyinHash.Add(-11798, "yang"); _pinyinHash.Add(-11781, "yao");
        _pinyinHash.Add(-11604, "ye"); _pinyinHash.Add(-11589, "yi"); _pinyinHash.Add(-11536, "yin");
        _pinyinHash.Add(-11358, "ying"); _pinyinHash.Add(-11340, "yo"); _pinyinHash.Add(-11339, "yong");
        _pinyinHash.Add(-11324, "you"); _pinyinHash.Add(-11303, "yu"); _pinyinHash.Add(-11097, "yuan");
        _pinyinHash.Add(-11077, "yue"); _pinyinHash.Add(-11067, "yun"); _pinyinHash.Add(-11055, "za");
        _pinyinHash.Add(-11052, "zai"); _pinyinHash.Add(-11045, "zan"); _pinyinHash.Add(-11041, "zang");
        _pinyinHash.Add(-11038, "zao"); _pinyinHash.Add(-11024, "ze"); _pinyinHash.Add(-11020, "zei");
        _pinyinHash.Add(-11019, "zen"); _pinyinHash.Add(-11018, "zeng"); _pinyinHash.Add(-11014, "zha");
        _pinyinHash.Add(-10838, "zhai"); _pinyinHash.Add(-10832, "zhan"); _pinyinHash.Add(-10815, "zhang");
        _pinyinHash.Add(-10800, "zhao"); _pinyinHash.Add(-10790, "zhe"); _pinyinHash.Add(-10780, "zhen");
        _pinyinHash.Add(-10764, "zheng"); _pinyinHash.Add(-10587, "zhi"); _pinyinHash.Add(-10544, "zhong");
        _pinyinHash.Add(-10533, "zhou"); _pinyinHash.Add(-10519, "zhu"); _pinyinHash.Add(-10331, "zhua");
        _pinyinHash.Add(-10329, "zhuai"); _pinyinHash.Add(-10328, "zhuan"); _pinyinHash.Add(-10322, "zhuang");
        _pinyinHash.Add(-10315, "zhui"); _pinyinHash.Add(-10309, "zhun"); _pinyinHash.Add(-10307, "zhuo");
        _pinyinHash.Add(-10296, "zi"); _pinyinHash.Add(-10281, "zong"); _pinyinHash.Add(-10274, "zou");
        _pinyinHash.Add(-10270, "zu"); _pinyinHash.Add(-10262, "zuan"); _pinyinHash.Add(-10260, "zui");
        _pinyinHash.Add(-10256, "zun"); _pinyinHash.Add(-10254, "zuo"); _pinyinHash.Add(-10247, "zz");
    }
    #endregion

    /// <summary>
    /// 获得汉字的拼音，如果输入的是英文字符将原样输出，中文标点符号将被忽略
    /// </summary>
    /// <param name="chineseChars">汉字字符串</param>
    /// <returns>拼音</returns>
    static public string GetPinyin(string chineseChars)
    {
        byte[] byteArray = System.Text.Encoding.Default.GetBytes(chineseChars);
        int byteValue;
        StringBuilder sb = new StringBuilder(chineseChars.Length * 4);
        for (int i = 0; i < byteArray.Length; i++)
        {
            byteValue = (int)byteArray[i];
            if (byteValue > 160)
            {
                byteValue = byteValue * 256 + byteArray[++i] - 65536;
                sb.Append(GetPinyin(byteValue));
            }
            else
            {
                sb.Append((char)byteValue);
            }
        }

        return sb.ToString();
    }

    /// <summary>
    /// 获得汉字拼音的简写，即每一个汉字的拼音的首字母组成的串，如果输入的是英文字符将原样输出，中文标点符号将被忽略
    /// </summary>
    /// <param name="chineseChars">汉字字符串</param>
    /// <returns>拼音简写</returns>
    static public string GetShortPinyin(string chineseChars)
    {
        byte[] byteArray = System.Text.Encoding.Default.GetBytes(chineseChars);
        int byteValue;
        StringBuilder sb = new StringBuilder(chineseChars.Length * 4);
        for (int i = 0; i < byteArray.Length; i++)
        {
            byteValue = (int)byteArray[i];
            if (byteValue > 160)
            {
                byteValue = byteValue * 256 + byteArray[++i] - 65536;
                string charPinyin = GetPinyin(byteValue);
                if (!string.IsNullOrEmpty(charPinyin))
                {
                    charPinyin = new string(charPinyin[0], 1);
                }
                sb.Append(charPinyin);
            }
            else
            {
                sb.Append((char)byteValue);
            }
        }

        return sb.ToString();
    }

    static private string GetPinyin(int charValue)
    {
        if (charValue < -20319 || charValue > -10247)
            return "";

        while (!_pinyinHash.ContainsKey(charValue))
            charValue--;

        return (string)_pinyinHash[charValue];
    }

}
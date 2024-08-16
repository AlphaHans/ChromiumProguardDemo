## Clone
* cd chromium/src
* git clone https://github.com/AlphaHans/ChromiumProguardDemo.git


## Build
* gn args out/apk_demo
```
target_os = "android"
target_cpu = "arm64"
is_official_build = true
is_component_build = false
symbol_level = 1
is_debug = false
treat_warnings_as_errors=false
root_extra_deps = ["//apk_demo"]
```
* ninja -C out/apk_demo apk_demo

## Run
### case1: run success
* install apk
```
adb intall out/apk_demo/apks/demo.apk
```

* run demo on android phone
* logcat echo
```
2024-08-16 16:25:00.659  7630-7630  chromium                pid-7630                             I  [0816/162500.659254:INFO:webview_entry_point.cc(46)] hanszhli JNI_OnLoad start register jni
2024-08-16 16:25:00.663  7630-7630  chromium                pid-7630                             I  [0816/162500.663845:INFO:webview_entry_point.cc(52)] hanszhli JNI_OnLoad end
2024-08-16 16:25:00.670  7630-7630  hanszhli                pid-7630                             I  oncreate
```

### case2: run error
* modify  chromium/src/apk_demo/proguard.txt
```
-keep class com.demo.** {*;}
-keep class androidx.** { *;}
```
* rebuild and run on android phone
```
ninja -C out/apk_demo apk_demo
adb intall out/apk_demo/apks/demo.apk
```
* logcat echo
```
2024-08-16 16:30:04.869  8215-8215  chromium                pid-8215                             I  [0816/163004.869427:INFO:webview_entry_point.cc(29)] hanszhli JNI_OnLoad start register jni
2024-08-16 16:30:04.870  8215-8215  com.demo                pid-8215                             E  ----- class 'LJ/N;' cl=0x142dab80 -----
                                                                                                      objectSize=120 (224 from super)
                                                                                                      access=0x0000.0401
                                                                                                      super='java.lang.Class<java.lang.Object>' (cl=0x0)
                                                                                                      vtable (0 entries, 11 in super):
                                                                                                      direct methods (231 entries):
                                                                                                         0: void J.N.M$O7xE3y(java.lang.Object, java.lang.Object)
                                                                                                         1: void J.N.M$UJTj5O(long)
                                                                                                         2: void J.N.M$b45Vvn(long, int, int, boolean, boolean, int, int, java.lang.String[])
                                                                                                         3: java.lang.Object J.N.M$eaBDjM(long)
                                                                                                         4: java.lang.String J.N.M0AyjO$E()
                                                                                                         5: void J.N.M0s8NeYn(long, java.lang.Object, int, java.lang.String)
                                                                                                         6: void J.N.M1Kw17GB(long, int)
                                                                                                         7: long J.N.M1XOiRvG()
                                                                                                         8: void J.N.M1e4GdYZ(int)
                                                                                                         9: void J.N.M2$ANfTC(long, java.lang.Object, int, int, int, float, int, int, int, boolean, boolean, float)
                                                                                                        10: void J.N.M2$X0reE(long, int)
                                                                                                        11: boolean J.N.M2E1dEU9(long, java.lang.Object, int, int)
                                                                                                        12: void J.N.M2Nl8ID9(long, java.lang.Object)
                                                                                                        13: void J.N.M2P7BQ98(long, java.lang.Object, long, long, java.lang.String)
                                                                                                        14: void J.N.M2TRi32V(long, java.lang.Object)
                                                                                                        15: void J.N.M2WbOJ7$(long, int)
                                                                                                        16: boolean J.N.M2evocmp(long, java.lang.String)
                                                                                                        17: void J.N.M2z_jbiy(long, java.lang.Object)
                                                                                                        18: void J.N.M2zph6xH(long, java.lang.Object, int)
                                                                                                        19: void J.N.M3JV9hBl(long, java.lang.Object, int[], int[], java.lang.String[][])
                                                                                                        20: void J.N.M3TCxDs5(long, java.lang.Object, int)
                                                                                                        21: boolean J.N.M3suD0ji(long, int, boolean, int, int)
                                                                                                        22: void J.N.M47GdBO5(long, int)
                                                                                                        23: void J.N.M4SmPJiR(long, java.lang.Object, int)
                                                                                                        24: long J.N.M5_IQXaH(int, int)
                                                                                                        25: boolean J.N.M5uHFthk(long, int)
                                                                                                        26: void J.N.M651cEC1(long, java.lang.Object, int)
                                                                                                        27: void J.N.M6C2IQIc()
                                                                                                        28: int J.N.M6EY_9Mw(long, java.lang.Object)
                                                                                                        29: void J.N.M7giG0Ri(long, java.lang.Object)
                                                                                                        30: int J.N.M7rZ5uJE()
                                                                                                        31: boolean J.N.M8UuMlLD(long, int)
                                                                                                        32: long J.N.M8VcAwxi()
                                                                                                        33: float J.N.M8pzdQ$h(long, java.lang.Object)
                                                                                                        34: void J.N.M9HSgyay(long, java.lang.Object)
                                                                                                        35: void J.N.M9XfPu17(java.lang.String, java.lang.String)
                                                                                                        36: void J.N.MAaklmRW(long, java.lang.Object, boolean)
                                                                                                        37: void J.N.MAd6qeVr(long, java.lang.Object, java.lang.Object)
                                                                                                        38: void J.N.MAoRk69U(long, java.lang.Object, java.lang.String, java.lang.Object)
                                                                                                        39: void J.N.MB302_MP(long, int)
                                                                                                        40: int J.N.MBIRtXF8(java.lang.Object, java.lang.Object, int)
                                                                                                        41: void J.N.MBT1i5cd(long, java.lang.Object, long, int)
                                                                                                        42: void J.N.MCIk73GZ(long, java.lang.Object)
                                                                                                        43: boolean J.N.MCMbXu4W(long, int)
                                                                                                        44: int J.N.MC_p8PYl(java.lang.Object, java.lang.Object)
                                                                                                        45: void J.N.MCtaZNwj(long, java.lang.Object)
                                                                                                        46: void J.N.MDAxNisW(long, java.lang.String, int)
                                                                                                        47: long J.N.MDLMFMDS()
                                                                                                        48: long J.N.MDMdj6cc(int)
                                                                                                        49: void J.N.MDpuHJTB(long, java.lang.Object, long)
                                                                                                        50: void J.N.ME6vNmlv(long, java.lang.Object, java.lang.Object)
                                                                                                        51: java.lang.String J.N.ME9i0MKK(long, java.lang.Object, java.lang.String)
                                                                                                        52: java.lang.Object J.N.MEHdfwD0(java.lang.Object, long, int)
                                                                                                        53: void J.N.MEJD7Boi(long, int, java.lang.String)
                                                                                                        54: java.lang.Object J.N.MEPH2V3G(long, java.lang.Object, java.lang.Object, long)
                                                                                                        55: void J.N.MERCiIV8(long)
                                                                                                        56: void J.N.MEghf3b7(long, int, boolean)
                                                                                                        57: boolean J.N.MEjwJwuS(long, java.lang.Object, java.lang.String)
                                                                                                        58: void J.N.MFB2QCbe(long, java.lang.Object)
                                                                                                        59: void J.N.MFLUFEZc(long, java.lang.Object, byte[], long)
                                                                                                        60: java.lang.String J.N.MFP_K5qZ(java.lang.String)
                                                                                                        61: void J.N.MFfRzF$Z(long, int, int)
                                                                                                        62: long J.N.MFjTMMS_(java.lang.Object, int, float, boolean)
                                                                                                        63: void J.N.MFq0hOYg(long)
                                                                                                        64: void J.N.MGCvz8lp(java.lang.Object)
                                                                                                        65: void J.N.MGGbKqrZ(long, java.lang.Object, boolean)
                                                                                                        66: int J.N.MGKRBsYQ(long, java.lang.Object)
                                                                                                        67: void J.N.MGVJOCWv(long, java.lang.Object)
                                                                                                        68: float J.N.MGZajSAq(long, java.lang.Object)
                                                                                                        69: void J.N.MGnQU$47(long, java.lang.Object, long, java.lang.String)
                                                                                                        70: void J.N.MGuj6mQj(long, java.lang.Object)
2024-08-16 16:30:04.870  8215-8215  com.demo                pid-8215                             E      71: void J.N.MHopMqLX(java.lang.String, long)
                                                                                                        72: int J.N.MI8pU34f(long)
                                                                                                        73: void J.N.MJ$gNv5y(long)
                                                                                                        74: boolean J.N.MJGtghd9(long, java.lang.Object, int)
                                                                                                        75: void J.N.MJIG3QvD(long, java.lang.Object, int)
                                                                                                        76: java.lang.Object J.N.MJJFrmZs(long)
                                                                                                        77: void J.N.MJcct7gJ(long, long)
                                                                                                        78: void J.N.MJdorYDE()
                                                                                                        79: void J.N.MJj9v_ba(long, java.lang.Object)
                                                                                                        80: long J.N.MKzrMxwv()
                                                                                                        81: void J.N.ML40H8ed(java.lang.String, java.lang.String)
                                                                                                        82: void J.N.MLJecZJ9(java.lang.String)
                                                                                                        83: int J.N.MLQe1QEw(java.lang.Object, long)
                                                                                                        84: boolean J.N.MLjXc4lw(long, int, boolean)
                                                                                                        85: void J.N.MLlibBXh(boolean, java.lang.Throwable)
                                                                                                        86: void J.N.MM2CqKoK(long, java.lang.Object, java.lang.String, java.lang.Object, java.lang.Object)
                                                                                                        87: void J.N.MM4OAOXm(long, int)
                                                                                                        88: void J.N.MM7E4tBk(long, java.lang.Object, int, int, java.lang.Object, int, int, long)
                                                                                                        89: long J.N.MMQ1O_vA(long, java.lang.Object, java.lang.Object)
                                                                                                        90: int J.N.MMmvZ$nS(long, java.lang.Object)
                                                                                                        91: void J.N.MN$L7RbV(long, long, java.lang.String[])
                                                                                                        92: long J.N.MNZCYawX(int, int, int, int, int, int, int, int)
                                                                                                        93: boolean J.N.MNch0m9c(long, int, int, boolean)
                                                                                                        94: void J.N.MNm00fYN(long)
                                                                                                        95: void J.N.MNqjfk23(long, java.lang.Object)
                                                                                                        96: void J.N.MOM50EIZ(long)
                                                                                                        97: void J.N.MOikWIf9(long, int)
                                                                                                        98: void J.N.MOkhqs8N(long, java.lang.String)
                                                                                                        99: void J.N.MOkngxPY(java.lang.Object, long, int, boolean, boolean, java.lang.String, int, int, long, float[], float[], int, boolean)
                                                                                                        100: int J.N.MOmBVeTt(java.lang.Object, long, long, int)
                                                                                                        101: void J.N.MOzXytse(long, java.lang.Object, long)
                                                                                                        102: void J.N.MPQKLw45(long, int, int)
                                                                                                        103: void J.N.MPTT407x(java.lang.Object, long)
                                                                                                        104: void J.N.MPaf3s5k(long, java.lang.Object)
                                                                                                        105: void J.N.MQAm7B7f(long, java.lang.Object)
                                                                                                        106: void J.N.MQTompEl(long, java.lang.Object)
                                                                                                        107: float J.N.MQY9Ofp7(long, java.lang.Object)
                                                                                                        108: boolean J.N.MR5ZSvGM(long, java.lang.String, java.lang.String, boolean)
                                                                                                        109: float J.N.MRQrYl4t(long, java.lang.Object)
                                                                                                        110: void J.N.MRbPfCZQ(long, java.lang.Object)
                                                                                                        111: void J.N.MSZPA7qE(long)
                                                                                                        112: void J.N.MSkFYnu9(long, int, int, int[], int, long)
                                                                                                        113: void J.N.MT6tcXz3(java.lang.String[])
                                                                                                        114: boolean J.N.MTBNGzHX(long, int)
                                                                                                        115: void J.N.MTDQeb$o(long, java.lang.Object, float[])
                                                                                                        116: float J.N.MU6WBitK(long, java.lang.Object)
                                                                                                        117: void J.N.MUFA7yj7(long, java.lang.Object)
                                                                                                        118: void J.N.MUH2vhAN(long, java.lang.Object)
                                                                                                        119: void J.N.MUf_fHKN(long, java.lang.Object, int)
                                                                                                        120: void J.N.MV00Qksi(long, java.lang.Object)
                                                                                                        121: void J.N.MV9yuwVC(long, java.lang.Object, java.lang.Object)
                                                                                                        122: int[] J.N.MVBiMGvZ(long, int, int, int)
                                                                                                        123: void J.N.MVuu0R4P(long, int, int, int)
                                                                                                        124: void J.N.MWM1LN92(int)
                                                                                                        125: void J.N.MWNjxKcW(long, java.lang.Object, float)
                                                                                                        126: void J.N.MX$D6jYE(long, java.lang.Object)
                                                                                                        127: long J.N.MXGgOw9k(java.lang.Object)
                                                                                                        128: float J.N.MXbY07SE(long, java.lang.Object)
                                                                                                        129: float J.N.MYP0SLZ2(long, java.lang.Object)
                                                                                                        130: void J.N.MYa_y6Dg(long, java.lang.Object, byte[], java.lang.Object)
                                                                                                        131: void J.N.MYwg$x8E(long)
                                                                                                        132: boolean J.N.MZ7sDynr(long, java.lang.Object, int)
                                                                                                        133: void J.N.MZCKcdTH(long, java.lang.Object, byte[])
                                                                                                        134: java.lang.String J.N.MZEbjzws()
                                                                                                        135: java.lang.String J.N.MZJ2lrZY(java.lang.String)
                                                                                                        136: void J.N.MZJzyjAa(int)
                                                                                                        137: boolean J.N.MZcfOSQW(long, int)
                                                                                                        138: java.lang.Object J.N.MZhgS7uU(java.lang.Object, java.lang.Object)
                                                                                                        139: void J.N.M_7y1FCn(long, java.lang.Object)
                                                                                                        140: void J.N.M_y76mct(java.lang.String)
                                                                                                        141: void J.N.MaKNZo8k(long, java.lang.Object, int, byte[])
                                                                                                        142: int J.N.MavOU0SM(long, int, java.lang.String, boolean, boolean, boolean)
                                                                                                        143: void J.N.Mb4JvlL7(long, java.lang.Object, double, double, double, double, double)
                                                                                                        144: void J.N.MbPIImnU(long, java.lang.Object, int, long)
                                                                                                        145: float J.N.Mc0wiJ8$(long, java.lang.Object)
2024-08-16 16:30:04.870  8215-8215  com.demo                pid-8215                             E      146: float J.N.McEG$Qxu(long, java.lang.Object)
                                                                                                        147: boolean J.N.McKjfBnu(long, int, boolean, int, int)
                                                                                                        148: boolean J.N.Mcw1yi1C(long, java.lang.Object, java.lang.Object, long, long, int, int, int, int, float, float, float, float, int, int, float, float, float, float, float, float, float, float, float, float, int, int, int, int, int, boolean)
                                                                                                        149: boolean J.N.MdFi6sVQ(long)
                                                                                                        150: long J.N.MdLvmXEa(java.lang.String, java.lang.String, short, boolean, long, long)
                                                                                                        151: void J.N.MdOwtyr6(long, java.lang.Object, int)
                                                                                                        152: java.lang.String[] J.N.MdQEl6jg(java.lang.String, java.lang.String)
                                                                                                        153: void J.N.MdZBZ$ST(long, java.lang.Object, long, byte[])
                                                                                                        154: void J.N.MdhaXGcn(long, java.lang.Object)
                                                                                                        155: void J.N.MeALR1v2(long, java.lang.Object, java.lang.Object, java.lang.Object)
                                                                                                        156: void J.N.MeoE5HbI(long, java.lang.Object)
                                                                                                        157: void J.N.Mf7HZHqV(long, java.lang.Object, byte[], int, byte[])
                                                                                                        158: boolean J.N.MfTAAcu8(long, int, float)
                                                                                                        159: void J.N.MffNhCLU(java.lang.String, long)
                                                                                                        160: void J.N.Mfq$ZJpW(long, java.lang.Object, int, int)
                                                                                                        161: void J.N.Mg0W7eRL(long, java.lang.Object, int)
                                                                                                        162: void J.N.Mg2XGOMM(long, java.lang.Object, int)
                                                                                                        163: void J.N.MgUhdCLo(long, java.lang.Object, double)
                                                                                                        164: void J.N.MgWlsTs7(long, java.lang.Object, boolean, int)
                                                                                                        165: java.lang.String J.N.MhBmyxCD()
                                                                                                        166: void J.N.MhKumtZE(long)
                                                                                                        167: int J.N.MhMiVz6m(long, int)
                                                                                                        168: void J.N.Mhc_M_H$(long, java.lang.Object, long, long)
                                                                                                        169: void J.N.Mi32vqDA(java.lang.Object, long)
                                                                                                        170: void J.N.MiJIMrTb(long, java.lang.Object, long)
                                                                                                        171: void J.N.MjxIGcDd(long, java.lang.Object)
                                                                                                        172: void J.N.Mk$gnuuz(java.lang.Object, int, java.lang.String)
                                                                                                        173: void J.N.Mk8V79M2(long, java.lang.Object, byte[], java.lang.Object[], boolean, boolean)
                                                                                                        174: void J.N.MkUGEqr$(long, java.lang.String)
                                                                                                        175: boolean J.N.MkaakTGI(long, int)
                                                                                                        176: void J.N.MkqvrLoV(long, java.lang.Object, java.lang.String, java.lang.Object, java.lang.Object)
                                                                                                        177: int J.N.Mkun8eIV(java.lang.Object, long, java.lang.Object, int, java.lang.Object, int)
                                                                                                        178: void J.N.Ml5G_GLY(long, java.lang.Object)
                                                                                                        179: void J.N.MlztHl3v(long, int)
                                                                                                        180: void J.N.Mm$QSrAo(long, java.lang.Object, boolean)
                                                                                                        181: java.lang.Object J.N.Mm6zKFIo(java.lang.Object, long, long, long, int)
                                                                                                        182: java.lang.Object J.N.Mm9rCM0m(int)
                                                                                                        183: void J.N.MmgQYR9M(long, java.lang.Object)
                                                                                                        184: void J.N.MmhSkOYV(long, java.lang.Object, java.lang.String, byte[])
                                                                                                        185: void J.N.Mmi_qOX8(long, java.lang.Object, byte[], java.lang.Object)
                                                                                                        186: int J.N.MmkSmonh(long)
                                                                                                        187: void J.N.MmnW7gQC(long, java.lang.Object, int, boolean)
                                                                                                        188: boolean J.N.Mmo4i01Z(long, java.lang.Object, int, boolean)
                                                                                                        189: void J.N.Mn3dG6eh(long, java.lang.Object)
                                                                                                        190: void J.N.Mn9Gzi$d(long, java.lang.Object, int, byte[])
                                                                                                        191: long J.N.MnPIH$$1(java.lang.String, boolean, long)
                                                                                                        192: int J.N.MnVi6Frs(long, int)
                                                                                                        193: boolean J.N.MnfJQqTB()
                                                                                                        194: void J.N.MnkvkoGY(long, java.lang.Object, java.lang.String[], float[], boolean)
                                                                                                        195: void J.N.MnvYa0QF(long, java.lang.Object)
                                                                                                        196: void J.N.Mo4Rd8TE(long, java.lang.Object, boolean)
                                                                                                        197: long J.N.MoCt2aB7()
                                                                                                        198: void J.N.MotttR54(long, java.lang.Object, boolean)
                                                                                                        199: void J.N.MpF$179U(long, java.lang.Object, long[])
                                                                                                        200: void J.N.MpJkwIUo(long)
                                                                                                        201: int J.N.MpcpmTlm(java.lang.Object)
                                                                                                        202: void J.N.MqHdTL15(long)
                                                                                                        203: long J.N.MqPi0d6D(java.lang.Object, long, long, boolean)
                                                                                                        204: void J.N.MqbF3KiE(long, java.lang.Object)
                                                                                                        205: void J.N.MqqhDONa(long, int, int, int)
                                                                                                        206: void J.N.Mqw5545M(long, java.lang.Object)
                                                                                                        207: void J.N.Mr6$Ko2f(long, java.lang.Object)
                                                                                                        208: long J.N.MrGiPMK4()
                                                                                                        209: void J.N.MrHXg7he(long, java.lang.Object)
                                                                                                        210: void J.N.Ms4vaKl$(long, int, int, int)
                                                                                                        211: void J.N.MsBIPWH$(long, java.lang.Object, float)
                                                                                                        212: boolean J.N.MsCvypjU(java.lang.String)
2024-08-16 16:30:04.870  8215-8215  com.demo                pid-8215                             E      213: long J.N.MsTyiXfW(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, boolean, long)
                                                                                                        214: void J.N.Mt26m31j(long, java.lang.Object, int)
                                                                                                        215: void J.N.MtWWjNjU(long, java.lang.Object, long, byte[])
                                                                                                        216: float J.N.MtgfnGGz(long, java.lang.Object)
                                                                                                        217: void J.N.MulYy5b7(long, java.lang.Object, byte[])
                                                                                                        218: void J.N.MumkJZ3e(long, java.lang.Object, long, java.lang.Object)
                                                                                                        219: java.lang.Object J.N.MunY3e38(long)
                                                                                                        220: void J.N.Mw73xTww(java.lang.String, java.lang.String, long)
                                                                                                        221: int J.N.Mxt_kc4Q(long, int)
                                                                                                        222: void J.N.MyRg_lPt(long, int)
                                                                                                        223: void J.N.My_SIOp6(long, java.lang.Object)
                                                                                                        224: java.lang.String J.N.Myi_XSsy()
                                                                                                        225: void J.N.Myj2LnkZ(long, java.lang.Object, int)
                                                                                                        226: void J.N.MyoFZt$2(long, java.lang.Object, java.lang.String, int, java.lang.String, java.lang.String[])
                                                                                                        227: int J.N.Myx2EYmS(long, java.lang.Object)
                                                                                                        228: void J.N.Mz9c1Rem(long)
                                                                                                        229: void J.N.MzDIdqgH(long, byte[], int, int, long)
                                                                                                        230: int J.N.MzRCryEE(long, java.lang.Object)
2024-08-16 16:30:04.870  8215-8215  com.demo                pid-8215                             E  Failed to register native method J.N.MegOH44r(J)V in /data/app/~~F1L2wnTqj4mn8SwHfrqQzw==/com.demo-hko5-U18O6TTEVOkzbXvIg==/base.apk
2024-08-16 16:30:04.870  8215-8215  jni_zero                pid-8215                             I  jni_zero_helper.h:37 RegisterNatives failed in gen/jni_headers/apk_demo/libdemo__jni_registration_generated.h
2024-08-16 16:30:04.870  8215-8215  chromium                pid-8215                             I  [0816/163004.870269:INFO:webview_entry_point.cc(32)] hanszhli JNI_OnLoad RegisterNatives failed
```

Failed to register native method J.N.MegOH44r(J)V in /data/app/~~F1L2wnTqj4mn8SwHfrqQzw==/com.demo-hko5-U18O6TTEVOkzbXvIg==/base.apk

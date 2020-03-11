#include <iostream>
#include <string>
#include <cstring> 
#include <thread>
#include <filesystem>
#include <fstream>

// String to encryption, 2 hours

using namespace std;

char Filename[100];

bool charSignatureOK = false;

int signatureCharLength = 120;
int charHashLength = 239;
int charHashLenghtPlusOne = 240;
int trackCharCount = 0;
                                    // char: 120 count.
std::string charSignature[5] = {    "-2ID9ZCV-9PC2BQB-YAXLXWH-5BJH8SV-JKPU3DK-1YUO2AI-J06Y355-63H5CTH-V7YENBB-V9KYIR4-Z2LFAAZ-USO9K8Y-WM4DOQ1-O0QA3N9-VMW5PNI",
                                    "-9TZ899U-L6GDJNN-SDZVPZK-6KAC1UA-IAU7OXP-2GP8FTR-8G9FV0I-7O9QCPH-O4V5DPX-4C7AWQG-G1QV6U1-6785D8J-99N33WD-FD5ONX2-B8P9SQP",
                                    "-3OX4JRW-PSB54N3-OUD4YU4-OLQQI5R-QUO7HW0-ZUPSAU9-PSXNSEW-6LGQN3K-Z6UYGX3-APOUAUX-BSMYB8O-HOIOLQY-VATA2OA-1WF4LNY-VHTCRHH",
                                    "-5LVMMDH-222OCJK-5DO43FV-7SRQMQV-PPSWS2J-RK7588P-5ERPNVA-DLONFWP-WCIKXUZ-COP9K5E-OCIL42I-CTYCFRK-KAGT7D2-D1B2F0C-4ZQGOX2",
                                    "-I71MQZI-8NF6F83-5Y4WM1K-6ZC7QNX-PKF0Y81-05WKHLA-A8YSMTA-1GOAZUM-1CGUMY8-RGU7G1I-DC1J056-PRUBBSD-7WN7L8F-PQEANZQ-VIW2CU1" };

// values A-Z, and 0-9                  char: 239
std::string charHashArray[36] = {   "N2BWUYD-8R25O45-9Y4SFD2-E5OMS38-XBGGHE3-1R0ADWI-42X83AA-370J6RL-3PAZXQK-QAZ0WWR-N2BWUYD-SPIEST5-8NCF7LU-S9MMUR9-RT6ZI05-8UIJQVQ-HBTRLMF-UG7FL76-CBRZ89H-XREDF86-XVCIA8A-XLVW5TU-331DCLU-9RH69M2-WR7HUJZ-PPWQC1S-V36HXCO-O9RGN55-N226HB0-3YHUZ5G",
                    /* 1*/          "M75WYB5-2WAQST2-0WQ1BHR-BFH1YQM-K1YM531-YBDUCO0-7F3L76G-VENF74W-3P96QAY-DVXCOM2-ZIZED1E-N2BWUYD-EDK2ZYJ-KCGMVPW-P13ABEH-5DQ45QI-G7NM6AW-MRCQOH0-DS2NPQW-ATQFC8F-PZPUPV4-R2IVDZU-JQ4GZQH-35KYFR7-YIN1LMT-LXSFEL7-XDQ1PRN-UR55Q3E-N0N4UKW-ETT06LF",
                    /* 2*/          "TYMI9KD-TFMPB7I-4LA3UX4-4C9PLUL-LUTOK85-BDXDD8R-L3C0AGT-RWMUIKT-28YT42D-EPFBVNW-K9K3C9F-QZT8KE3-N2BWUYD-93Y9HN4-5Y45YYF-HAU3RB0-ZMDIV3S-DOBXP28-NW9SJMB-F80RD21-VDD3965-3495I7P-IZJL6CE-18W4LPW-B7XQ91T-T42SM7D-HQIDRBS-5U6VTLB-Q53PR3S-CNPMSJ9",
                    /* 3*/          "J2BL6LA-ASOPR4C-4R6SSJ5-33ICB9R-QHFSCMH-5CBOOBZ-UNDUEA5-RMMVOQZ-OXNXBSU-ZLUYOW6-42G4715-S20CSOB-X8A5FP9-N2BWUYD-ZVVAVOS-3JVALE3-3AIM61L-69V5RG6-0XHWKUO-OH13982-Y6R23LX-8D3GMJW-6A3I58W-AA6TD5U-UX7JLCF-JCXE762-B0WLOMS-J39BJM6-B0WG6H8-YA0MRPK",
                    /* 4*/          "9TZXOS8-XUGYJKZ-8L3S82H-69T0YQR-56XPYW7-D8X1ZS2-GBN1F35-3X50GNZ-8D8R6TY-X1U9LY8-L7JBXDO-XHWZII3-9G34IN2-VBP5Z8X-N2BWUYD-MLI8VXX-LWKDQMI-9834G5L-2UAUZ82-227EKUN-VEP360C-VV9JGXG-8JP50N6-47PNMGV-S3OCCB3-7EIAZ4P-H92KJZE-HV0FMYV-37W01LR-LDWERFH",
                    /* 5*/          "V0N8RH2-DWLZWJ3-O45535O-3R5YCP0-9QD51D7-SXCCDDO-0HPJJCX-FCGPIBE-AW1DH02-HQ9RJ17-5R7F8RW-LWCG2LT-2JSGEH6-8BMOBOB-T3QTRCN-N2BWUYD-R8XTI2Y-Y31DM24-2AKDL3R-WFQXYMZ-XJLX51U-GA5EWY8-83V1BVC-Q50XID0-Z5Y6CNK-4DOLK8I-7VWWY1G-QWEG6Y4-I9OBFEC-QWDVMER",
                    /* 6*/          "J0D58K5-A0SK7X8-EOTPJDZ-INXFDB2-QUB6VVD-LB4Q8XO-Y1RZ7O2-Q6636R9-32Y7OW0-T3SM841-N2BWUYD-WBL55HR-TEKDJVM-7MLV161-S7WJ6X1-A2480UW-GZKQKG2-PXAY5B6-ZA6JQQP-R01ZA08-L658IAT-TSWD5LW-02WRBJV-SGY9S1C-8PFD1BP-ZSATF5I-JCWITVV-XOZHK5Q-WH7BOBN-3EONNVV",
                    /* 7*/          "N2RZPHM-YX4NO04-XJJCFCE-V4NI6MT-HIKLLQP-03P50UI-GYT7LLF-5BEP6OK-A77FJAD-GCMHV1V-APDLV1V-OR247WU-6L3A4CT-H6MXVK8-I2BC0U1-A1ZMDRZ-ZJGICWD-N2BWUYD-O5DXIGZ-H4F0D1R-E8M4MJY-JF0XGAW-NZBKNM0-QK0RAN4-OLWKOOC-BN2IM3T-BKAXAHI-XBCLZ0H-HTM4B0S-92E04TD",
                    /* 8*/          "D0LWASL-YAWEDAC-NXOKSW3-FMONZJX-6O9NJXO-M619RS7-WSW6I7L-JJNWW9K-PO7UKV0-RJFQ5TM-9S1VEVA-5V91RHM-K7M76P7-N2BWUYD-5T1J7BL-PIIR64W-AGMQ4WS-B1LDC4N-KONNJ9H-OLBLVVQ-IATVOGX-Z8WIVMA-GGCVE6M-CD3NQ2J-XNMA6Z6-A4D3MZ2-W66OTB6-V2ZUM4X-M4NLG9C-FZ8QM6R",
                    /* 9*/          "VITAV69-QUYNUV8-03PO8SU-GR3XL4S-P08UBHD-0ENDEUM-G0820GA-IHWW1C4-6N4OPD7-K9RZWAM-YA0YVC9-2XBRXF4-FPOU21B-SXRD29C-07L1GRL-DMCLQ51-ZZ9JP7X-YOLT1Y3-N76S0PK-0UCWTTL-OQB3XIR-090NAPJ-58LT4LC-2OCMJ0N-4HN0EKX-N1U5L0P-T7KYG9V-SY7ZNDR-GX505QP-BDSDCJV",
                    /*10*/          "4X0GCZD-0PRXQ7B-HDNBBQH-UHV4EFJ-YVJACHX-U09CDHF-CJXCIYU-IREUMMD-ZRTUYXG-SXTUCAB-V4ZK9WD-WBC8UAY-ZJ7HYBF-G4PUL2E-FYBTME4-2N9FLRO-6GTNUG7-69P1MP4-T8WB8KT-3ZTG6KC-DEW62Z0-GLR2B6C-8SONV6X-10NFRS6-PQMBBOZ-POHR3J6-AB3HN16-TP4I555-9H93RWR-D480Q1D",
                    /*11*/          "1H8DSPR-RDL91S5-2H6XXZ6-0V60JZK-2G316SK-UHM1BXL-836D7C1-K1E0YCT-L9EM0ST-N2BWUYD-MVEA2Y2-WEMIX5P-0K95UGF-2JJ21US-D4DLDMS-3055C48-LX4CYMK-PQ79PYY-N2BWUYD-QP8S9TC-9NN7HWX-04VELVT-68BRCZH-HOFEN7P-EUXPL2Y-9WLGZHU-Q03D1GX-G6ETVAB-6KF3E15-EOGXX0S",
                    /*12*/          "BFL5MUB-J2KD2PD-Q346O6A-1JWW5S7-4UGDTXM-7FUPUXB-YSKQUKG-GX8SCQK-X1GJV2H-IMGTCUM-HQ3Z54S-KUV9J3O-XZ7DXRQ-ARYQB7N-UIN8HFU-2UE9239-N2BWUYD-N19CNE9-2C7JBH0-XTNP4IY-XI91XP5-ETXU2G5-P66K1B2-C47SOTX-BZNP8BU-0LY6GXI-THTGTJ3-LI5SYX6-8XXBEB6-UYHUDE8",
                    /*13*/          "4QK200H-MAQ5JXF-X1LUIWW-YTB9083-JF4VXNQ-A9AXWTR-BJ8NWXA-FTCI9IE-1EVYV42-JON8I12-BHWHY6B-TRZMONE-I1DJC4U-N2BWUYD-ZY6S7MI-1EUXAYZ-L16CGL4-VM5NEYF-BXRULJY-4Z1ZSKD-TZ8AWX5-UQYVQFL-ERNPJIL-YSM9YHS-Y56RQCB-MFRBVGD-CZYE5Q6-BDYMUYU-AIXV009-AZS529F",
                    /*14*/          "DJ7DL8O-XYUEABJ-ENU4V0C-41VHVJ2-FEERYBD-1BW7VTP-JG54L83-N4M6MRV-9RRIEXT-54BU4C9-BRU4PI8-T2ZZQIA-9R5O0JA-BBLXASU-N2BWUYD-U7VOLMC-EFSDM4W-MX6KYAT-2T10GYI-FYMUZ52-C2E4U9T-U6EI7NU-NNEOX1I-0OPKVE3-12981PZ-9Q0OWTC-GKT7FRJ-NTG8M5T-H0JJPFX-B4MPB7I",
                    /*15*/          "ZSAQGSV-TV16RBD-X99AQ0H-AG1QHZQ-42LFKE0-3V34J19-5DGJV4U-PU60Q9I-1OWDZ5X-Y0NET2I-3CHTU6C-MXUSH00-NOQLD2I-JS7E4AD-7FDAANG-NZWWJQU-VF86NH8-N2BWUYD-TJ1CM4L-WIVECGW-Z4Z11MY-Q1KE868-46983IU-KNMYFJH-N6RVTN1-WA626Z3-Q46WSQ6-E832LJY-OZN0PN1-L4XPT54",
                    /*16*/          "HPAW0F6-8CYC3A0-39MH7KH-MRAZGPQ-SPKHUME-IL8U0Y0-GK1KHOG-7T3H454-LBAA5X9-039BCD8-FODR5YG-N2BWUYD-0L623IS-RG89F76-J4FLUPY-0BZBS0S-SMVFF5L-MJ66RK6-76DUPYJ-25ZK8NA-MB341AP-RSXXIR6-9GWIL9T-864II7F-WCNZHHN-JFL1F4T-B9TDCK1-56UMKD5-UDVOZ8R-DXT50F6",
                    /*17*/          "03PRUJP-47PPO6Y-UJ4JYZI-TJ6NWQN-KKVVNUH-YJ1E4GN-TIFNRSA-WYUM9QB-4KCFM2H-DU1J7OL-N3SB11B-UHQVZZ5-9HCACYH-N2BWUYD-ZP0LYNZ-ZJHCG2C-X2N1AJY-TZINSBB-FVT25ZI-GL28694-C7AEFPZ-GUK60OS-IZJ5X58-SUDAL1N-O23HKD3-TVUXL29-4ODKL0C-L5FTNXS-RO2S82J-VH6FNC7",
                    /*18*/          "7TTTKR6-CAGDBWS-W70UGSQ-HRIWM9Y-VFM05GK-RFF919W-NM6XJ72-5I13DFW-EDRHXVM-JZ4I0IZ-DOHYV5Z-XNS9WZA-5JQ9JNC-F8344AZ-N2BWUYD-POUGLGX-OVTSHQC-KQREA1H-VQONCOE-3JLJ73Z-TWAYG8R-U8PDXXE-W44QNH4-E8WHDRD-CSKIHTT-1762Z5J-Z9RG8EW-DGERPUY-VDHNJQX-9FLUJ8M",
                    /*19*/          "ULF3N8V-54BQ4EQ-RNBZ949-OMJ2P3L-OAU2FJ9-G3XG352-ZX9B4RJ-3OV2Y9S-HMIH2P0-ULLIQBX-YDRWY3F-QDVLF2R-3ITHNCC-LGNAY7I-CJHKZIT-KNLE22J-N2BWUYD-VDIP1JP-E5K2JQT-3EQS2MN-KOM4Q9L-326TPOR-EKA54ML-ZZ7IMMH-HKC3E2Q-5UZLA64-9UMOQ75-TNURFCT-8T29TX5-4M5JMCD",
                    /*20*/          "LHLD445-T54WFW1-TRDPR27-YJ11BGZ-JZFUAMP-S1Z3IZ8-JDUPEHC-ZZB8R50-S7ACGUZ-XC02JSW-3PM7C81-D520E13-AMYBOA2-R2D8R27-NCQYBEJ-QYNFU17-UEMX5Q2-N2BWUYD-IOOPP3L-70U9OO3-WANGBWE-T6TKCO1-V8BFRMW-XCRIJ4O-ZKQF2M4-9WP7M7F-ROVR3E3-JJWYZXO-6Y3ZEKR-EPWFMOC",
                    /*21*/          "DRJ4Z2V-X8JXQQH-NQQL3H9-NNVHQA8-2DIQ8VV-6RKZ4M7-OZH868C-CD5W6B6-K1O6V6O-1FQQNZ4-GIARGQI-0U8IONS-VBUDNP9-KDOW1Z1-DIJIK78-67AR6QQ-5T0UBEY-KVUBWE2-3NVVM8U-N2BWUYD-4BXV3M3-UZ0CA7K-7A4AOWD-H453QBJ-8EX0RH0-OKRN4KB-X42H53U-XI3ZP61-LA6CC0H-ROAU3E5",
                    /*22*/          "6KFHRCL-QPJL7YN-3W761ZH-H92W2PX-RDBEACY-HTQ56TZ-E7EPQL5-08PCFX3-3RQKOTY-N2BWUYD-NWCODWG-UPIKCKL-ICZE6RL-2D46ZXT-1H50FVC-AAOCJVB-3WSGHT1-XZUZPQC-FIT4GUF-UGSTR6V-IOGSA5B-CROSF8I-LR1H57V-2Z6FAM9-HKGD6IV-APWPK8H-00LYWXK-QEBJNA8-6JAAPI0-O83XRUR",
                    /*23*/          "TSUCKC2-20HVJ3G-6SFUNG7-F2VC1H1-XO4FRW4-RNDIMQX-F5N7FZ4-67RCDXS-KCNSVGY-8QKF6A3-SWLMAM3-DQ0GSFW-NFW1XZN-4Y11Q38-ZY75PHW-N2BWUYD-OK6HZJE-AZM40KV-VCFYGLR-L13R63E-8DT085K-AWJATZB-H25LC4O-FFOWVZY-ZCGCZMD-GM2H7X2-KI5YVMC-DUP0PPI-ZSQM8WP-874BS5H",
                    /*24*/          "R2MSN38-1Q7C7VJ-OTYQE07-HKC4AOB-QI2H7A3-YDO0TRV-EEFMP1U-5Y1XJPF-W4IWSUM-YYA6OSE-3TWV1IQ-5WU8PNY-M6LR2Q7-1J7ET9R-02ON6Q9-ALY8UZ7-9TC346X-HKF1RF8-JIYVHXV-N2BWUYD-JUAJR87-CZ4Y91H-3CT1284-02MJUZP-M7LKNTR-GPMIZ0T-OTZHMH8-WTJ7X8I-G3PG184-X78NKIL",
                    /*25*/          "MCYYHYL-APWVE46-TW4IT7K-4KP1GRH-CRL24FP-JXQ29CJ-5ECO5G8-S622VGQ-7NBRB17-1IDVHO1-CE00FXZ-TYPIIFY-T6P0ORY-K4Z3BK7-UAOVI7T-4HEF2U5-BBM1GGV-ZXG98KU-N2BWUYD-H9ZTYEX-ILTJZTK-6IF7W3P-KTMWQNP-WXFXGBS-AO6TLK9-71ZCOCL-YX60KA7-GDCB9CO-M1W2UAF-FCDANWS",
                    /*26*/          "Z9XZDMU-YXN6QF2-EGF0MVL-5W3LI2J-71D91XR-VT0N71G-MVYEZ4M-N1M6SOS-AWBNYL7-1HK1JK5-T065RO5-YYIHXJB-CNGPKXC-IRJ5944-S3JEMXY-XLLH9WT-UJDB3YF-X95LE33-N2BWUYD-N0OBWYJ-PDH7YNM-B8P2E87-Y1XU9LA-CFSGT3E-BK0KQTJ-LDD3D09-NCZJ8GP-LOLWVUS-26FZH2V-Q03ATW5",
                    /*27*/          "QA7PT1Z-CN4IXE8-M19ZUOG-889GNOC-KYKXJIB-XFFPRXQ-5SRYMBH-BFA4MQQ-SBK3MBP-Q9CLUH7-237KKTV-2NKCZVU-55TNXDU-F1EZNVQ-3EC4O29-IE1OGAL-EW4KW6H-XB4T6AO-N2BWUYD-A12Y8ZW-FOY9KO0-3SBMC3L-B71IHNV-35N3LUO-ODKLA03-C8YGKYK-YDFOJRS-379V2SM-GIKCOB0-Q5D204K",
                    /*28*/          "U6XYRT6-GR3KUFK-BI1GO0L-T3EOBEJ-UHEBWEX-H0RMIJS-NQG18BI-8P7H4O0-JSMYBYK-QSKBPOB-FUBWWTH-ZVWRHDQ-7TULM3B-7J1FNIU-P0GHAKQ-Q98EKCX-YDUCO9A-N2BWUYD-LZERPQS-95J6JJT-5VUBL62-KWPEPAK-5CPIOGV-MHJ1GSJ-5MZCZJT-YBG9MWO-11OR97M-I9X35SY-YSE1KEJ-6M1HMZT",
                    /*29*/          "0VUIUYX-TEFZ1VW-815M4WL-2DDANXH-8SBJOYV-PTQ0B6X-D8T9DCK-V5OCN22-B8BIB2Y-VN8Y0WG-HNL41L4-N9IKU5I-P0A868W-COZCYHV-SREOIJS-3M7DLF9-N2BWUYD-2MTJ5GG-163TCKR-N44TALS-9IXB4C9-V0OX1O4-J7QIAYH-P2UE30Y-TBQ6KLB-SRUAIW7-649DZBM-RBR2O58-EZOFYET-RCKA7F1",
                    /*30*/          "7VJK2S1-VD07YJC-OZZ5EAM-1FXBUG1-QEYJSSD-9R5OALN-OJYSVE0-PENIQZ9-6BSLT5O-P0U854Z-70Y6NBH-LA1NYBL-184M6N4-AS1B321-NF3IF0Z-IKLO74X-N2BWUYD-79QBODM-LWHD4TK-XN8NI4M-19M9NO2-CCC4WNV-6XFGP3E-KTIQ6E6-GPVMD5E-DIDAL8U-1KYBIJ9-TGDI1VN-ED7GFVA-8S0M81B",
                    /*31*/          "WN1Y502-W5XCWGF-R50V1OW-W5MHWZB-IUP3XGW-EJWBRZP-7Y7GO3Y-WWZBVEO-IPHGGJU-CO8Z02J-31SX5IB-QCB3DUX-SDGSOHL-Y34ZJKF-KNB410G-9O0WOBB-LVZTYKU-N2BWUYD-BK3YZWU-YTZN39D-3M9I6AO-A5DY8VL-60R91PG-H0Z18SI-XM0DDG8-OZD1EKS-202QSJ9-UMK5D92-SWP9DLD-ZKQZSCP",
                    /*32*/          "5UWJSPX-AQ9WYGC-USQHTEP-DYUCP9B-UTM6BAV-HDXFQ7I-3YF2MWU-SR20C2Q-OEC6N99-OY44D29-N2BWUYD-3I0ZDEJ-94JUFUZ-ZNXGRR7-YNEEJ9A-XR4KR5S-W346N2M-104Q7I2-J9KQYVT-L290R3Y-M4CWMZN-8T49DIA-VFTRSR2-MYMM5SF-MFEJJJ9-EJPJSHF-Y8Q4C96-2BLHUAE-WCFI0AE-AAXXX2F",
                    /*33*/          "61WC5QT-RQM571I-123LS01-X6TSV7B-7BGVERP-T8Y36NZ-NB6F08S-1YETQ3N-B022P8G-ATQJMNH-KWU5IEK-5R2K6K3-N2BWUYD-35EG3C0-6DTULNR-ABH2WZK-A9C5EEZ-KP5BCJU-8B4N06V-7D4I3KB-ZAB9N0E-R7J6L1J-1C7LQMF-GJJE97G-AJEH9YP-2IHHMCV-S4GMJIV-LHXIFEQ-D37C5WJ-YMBFNBK",
                    /*34*/          "MCJJR37-WZU2C70-X2R9URD-2SMP65X-I59H3AF-2VJGVNR-HYBH2O0-DC4OAR5-KAPN9ZL-150RTX7-YXFTEXY-SVBQOM3-KLOJEF6-N2BWUYD-VN7K6VS-N6B1I4E-1OQ4JV8-NQZGHP9-9Y3HD6A-6PXZ5Z9-JYT4N0H-XVU7IXH-AHZ00PX-HEVF4RQ-N8FYWYE-18ONVWY-AQVRK1L-4NJLFDN-9VRRT8A-7ZRQATD",
                    /*35*/          "RSWKEXI-0DSM6DT-V6Q3AS5-E6UFY8L-FIL48C3-6I9N27K-P8U2VIE-QVUV2UC-U601LID-DZXSEKX-SF9CWB6-AJQ7YJ4-AHTNCAM-J0Z9V1U-N2BWUYD-FQ2XZBU-U7DE4OQ-ZIWU7UZ-FCQXNB4-70NL58H-5Y7KVM3-XD5BMB9-5KE1S7L-TDMELXM-IOVIWVT-Q660T5B-6WQYA6H-5LEK9DW-IORJPKQ-MNTOY6E", };

std::string getCharHashArray[20] = { "","","","","","","","","","", "","","","","", "","","","","" };
std::string someValues[20] = { "","","","","","","","","","","","","","","","","","","","", };
std::string charEncryptData;
std::string textBucket;
std::string finalUserText;
std::string username;
std::string encryptedString;

#pragma region 
/*
                                         <<<<Value table.>>> 

    A=0		B=1		C=2		D=3		E=4		F=5		G=6		H=7   
    I=8		J=9		K=10	L=11	M=12	N=13	O=14	P=15
    Q=16	R=17	S=18	T=19	U=20	V=21	W=22
    X=23	Y=24	Z=25	0=26	1=27	2=28	3=29	4=30   5=31   
    6=32	7=33	8=34	9=35  
*/
#pragma endregion 

// Convert our String into an Array
void StringToArray() {

    // We place our input in a string we can use
    std::string FileMeasure = username;

    // we make Temp equal to the size of the string
    int TempNumOne = FileMeasure.size();
    
    // we loop this many times
    for (int i = 0; i <= TempNumOne; i++)
    {
        Filename[i] = FileMeasure[i];
        std::cout << Filename[i];
        std::cout << std::endl;
    }
}

// Puts our encrypted data together in a variable "encryptedString"
void PutEncryptStringsTogether() {

    // While i is smaller than the length of our string...
    for (int i = 0; i < static_cast<int>(username.length()); i++) {
            
        // check each possible letter/number it could be.
        if (Filename[i] == 'a') {
            // and display encryption string in TABLE
            encryptedString = encryptedString + charHashArray[0] + "-";
        }

        else if (Filename[i] == 'b') {
            
            encryptedString = encryptedString + charHashArray[1] + "-";
        }

        else if (Filename[i] == 'c') {

            encryptedString = encryptedString + charHashArray[2] + "-";
        }

        else if (Filename[i] == 'd') {

            encryptedString = encryptedString + charHashArray[3] + "-";
        }

        else if (Filename[i] == 'e') {

            encryptedString = encryptedString + charHashArray[4] + "-";
        }

        else if (Filename[i] == 'f') {

            encryptedString = encryptedString + charHashArray[5] + "-";
        }

        else if (Filename[i] == 'g') {

            encryptedString = encryptedString + charHashArray[6] + "-";
        }

        else if (Filename[i] == 'h') {

            encryptedString = encryptedString + charHashArray[7] + "-";
        }

        else if (Filename[i] == 'i') {

            encryptedString = encryptedString + charHashArray[8] + "-";
        }

        else if (Filename[i] == 'j') {

            encryptedString = encryptedString + charHashArray[9] + "-";
        }

        else if (Filename[i] == 'k') {

            encryptedString = encryptedString + charHashArray[10] + "-";
        }

        else if (Filename[i] == 'l') {

            encryptedString = encryptedString + charHashArray[11] + "-";
        }

        else if (Filename[i] == 'm') {

            encryptedString = encryptedString + charHashArray[12] + "-";
        }

        else if (Filename[i] == 'n') {

            encryptedString = encryptedString + charHashArray[13] + "-";
        }

        else if (Filename[i] == 'o') {

            encryptedString = encryptedString + charHashArray[14] + "-";
        }

        else if (Filename[i] == 'p') {

            encryptedString = encryptedString + charHashArray[15] + "-";
        }

        else if (Filename[i] == 'q') {

            encryptedString = encryptedString + charHashArray[16] + "-";
        }

        else if (Filename[i] == 'r') {

            encryptedString = encryptedString + charHashArray[17] + "-";
        }

        else if (Filename[i] == 's') {

            encryptedString = encryptedString + charHashArray[18] + "-";
        }

        else if (Filename[i] == 't') {

            encryptedString = encryptedString + charHashArray[19] + "-";
        }

        else if (Filename[i] == 'u') {

            encryptedString = encryptedString + charHashArray[20] + "-";
        }

        else if (Filename[i] == 'v') {

            encryptedString = encryptedString + charHashArray[21] + "-";
        }

        else if (Filename[i] == 'w') {

            encryptedString = encryptedString + charHashArray[22] + "-";
        }

        else if (Filename[i] == 'x') {

            encryptedString = encryptedString + charHashArray[23] + "-";
        }

        else if (Filename[i] == 'y') {

            encryptedString = encryptedString + charHashArray[24] + "-";
        }

        else if (Filename[i] == 'z') {

            encryptedString = encryptedString + charHashArray[25] + "-";
        }

        else if (Filename[i] == '0') {

            encryptedString = encryptedString + charHashArray[26] + "-";
        }
        
        else if (Filename[i] == '1') {

            encryptedString = encryptedString + charHashArray[27] + "-";
        }

        else if (Filename[i] == '2') {

            encryptedString = encryptedString + charHashArray[28] + "-";
        }

        else if (Filename[i] == '3') {

            encryptedString = encryptedString + charHashArray[29] + "-";
        }

        else if (Filename[i] == '4') {

            encryptedString = encryptedString + charHashArray[30] + "-";
        }

        else if (Filename[i] == '5') {

            encryptedString = encryptedString + charHashArray[31] + "-";
        }

        else if (Filename[i] == '6') {

            encryptedString = encryptedString + charHashArray[32] + "-";
        }

        else if (Filename[i] == '7') {

            encryptedString = encryptedString + charHashArray[33] + "-";
        }

        else if (Filename[i] == '8') {

            encryptedString = encryptedString + charHashArray[34] + "-";
        }

        else if (Filename[i] == '9') {

            encryptedString = encryptedString + charHashArray[35] + "-";
        }

        else {
            
            std::cout << "There was a problem encrypting your <CHAR> data...\nExiting application";
            std::this_thread::sleep_for(chrono::seconds(3));
            exit(0);
        }

    }

    // Encryption variable.
    cout << encryptedString;
    
}

// Random number generation (for signatures)
int random(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Pick a signature, and add to to the end of our string variable
void addSignatureToCharString() {

    // start random seed
    srand((int)time(0));

    // store our random number
    int randomNumberForSignature;

    // generate the number
    randomNumberForSignature = random(0, 4);

    // if it's this number, get first index of charSig
    if (randomNumberForSignature == 0) {
        encryptedString = encryptedString + charSignature[0];
    }

    else if (randomNumberForSignature == 1) {
        encryptedString = encryptedString + charSignature[1];
    }

    else if (randomNumberForSignature == 2) {
        encryptedString = encryptedString + charSignature[2];
    }

    else if (randomNumberForSignature == 3) {
        encryptedString = encryptedString + charSignature[3];
    }

    else if (randomNumberForSignature == 4) {
        encryptedString = encryptedString + charSignature[4];
    }

    else {
        std::cout << "Error encrypting data: Code 44.\nExiting application...";
        std::this_thread::sleep_for(chrono::seconds(1));
        exit(0);
    }
}

// Send the string to A directory
void SendStringToFile() {

    // Create dir
    std::filesystem::create_directories("C:\\ACLG_String_Test");

    // put encrypyedString to file
    ofstream myfile;
    myfile.open("C:\\ACLG_String_Test\\encrypt_text.txt");
    myfile << encryptedString;
    myfile.close();
    
}

// CHECK the encrypted signature, is it valid?
void checkCharSignature() {
	
	int signatureCheckLength = charEncryptData.length();										// get full length of encrypted string, place in signaturechecklength
	int signaturePoint = signatureCheckLength - signatureCharLength;							// with lenth, we minus the signature length
	string getSignature = charEncryptData.substr(signaturePoint, signatureCharLength);			// then, we start from the beginning of the POINT to the end
																								// getSignature is now equal to a 120 char string

	try {

		if (getSignature == charSignature[0]) {
			charSignatureOK = true;
		}

		else if (getSignature == charSignature[1]) {
			charSignatureOK = true;
		}

		else if (getSignature == charSignature[2]) {
			charSignatureOK = true;
		}

		else if (getSignature == charSignature[3]) {
			charSignatureOK = true;
		}

		else if (getSignature == charSignature[4]) {
			charSignatureOK = true;
		}

		else {
			throw 78;
		}
	}
	catch (int x) {

		system("cls");
		cout << "Encryption ERROR <CHAR>. Error code: " << x << "...(shutting down.)" << "\n";
		this_thread::sleep_for(chrono::seconds(3)); // exit?
		exit(0);
	}

}

// Place our encrypted string into an array 
void charEncryptToArray() {

	int signatureCutOff;
	int holdLength;
	string newEncryptData;
	int findIndex = 0;
	int moveUpArray = 0;

	// first, we get the length of our string variable

	//cout << "Data length: " << encryptData.length(); "\n";

	checkCharSignature();

	if (charSignatureOK == true) {

		// whatever the length is, we grab the entire string except the last 3 digits (depending on character size of signatures). This will cut off the signature.

		holdLength = charEncryptData.length();
		signatureCutOff = holdLength - signatureCharLength;			// signature is now equal to length minus 3

		//cout << "\nData without Signature: " << encryptData.substr(0, signatureCutOff) << std::endl;

		newEncryptData = charEncryptData.substr(0, signatureCutOff);

		// Now we want to place our data in an array. 

		for (int findIndex = 0; findIndex < static_cast<int>(newEncryptData.length()); findIndex = findIndex + charHashLenghtPlusOne) {			// prev: 2 = 127 (amount of strings)    3 = 128 (string plus 1)

			//cout << "\n\nFor testing: " << newEncryptData.substr(findIndex, stringLengthForEach);

			// we then store each number into a slot.

			getCharHashArray[moveUpArray] = newEncryptData.substr(findIndex, charHashLength);

			moveUpArray++;
			trackCharCount++;

		}

		//cout << "\n\n--------------\n\n";
		// Lets print our array and check it works

		for (int i = 0; i < 9; i++) {

			//cout << getHashArray[i];
			//cout << ",";
		}
	}

	charSignatureOK = false;  // reset

	cout << "Element 1: " << getCharHashArray[0] << '\n';
	cout << "Element 2: " << getCharHashArray[1] << '\n';
	cout << "Element 3: " << getCharHashArray[2] << '\n';
	cout << "Element 4: " << getCharHashArray[3] << '\n';
	cout << "Element 5: " << getCharHashArray[4] << '\n';
	cout << "Element 6: " << getCharHashArray[5] << '\n';
	cout << "Element 7: " << getCharHashArray[6] << '\n';
	cout << "Element 8: " << getCharHashArray[7] << '\n';
	cout << "Element 9: " << getCharHashArray[8] << '\n';
	cout << "Element 10: " << getCharHashArray[9] << '\n';
	cout << "Element 11: " << getCharHashArray[10] << '\n';
	cout << "Element 12: " << getCharHashArray[11] << '\n';
	cout << "Element 13: " << getCharHashArray[12] << '\n';
	cout << "Element 14: " << getCharHashArray[13] << '\n';
	cout << "Element 15: " << getCharHashArray[14] << '\n';
	cout << "Element 16: " << getCharHashArray[15] << '\n';
	cout << "Element 17: " << getCharHashArray[16] << '\n';
	cout << "Element 18: " << getCharHashArray[17] << '\n';
	cout << "Element 19: " << getCharHashArray[18] << '\n';
	cout << "Element 20: " << getCharHashArray[19] << '\n';

	//system("pause");

}

// GET our local encrypted string
void GetCharFromFile() {

	// Create a text string, which is used to output the text file
	string myText;

	// Read from the text file
	ifstream MyReadFile("C:\\ACLG_String_Test\\encrypt_text.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {

		// Output the text from the file

	}

	// put our Data into the .exe
	charEncryptData = myText;

}

// Turn our encrypted array into Text
void ArrayToText() {

	int i = 0;
	int j = 0;

	while (trackCharCount > 0) {

		/*if (getHashArray[i] == "emp") {
			break;
		}*/

		try {

			// check if our first encrypted string is equal to our first fixed Hash Array value
			if (getCharHashArray[i] == charHashArray[0]) {
				someValues[j] = "a";		// if it is, we know 0 = a
			}

			// if not, we check "1" which we know is "b"
			else if (getCharHashArray[i] == charHashArray[1]) {
				someValues[j] = "b";
			}

			else if (getCharHashArray[i] == charHashArray[2]) {
				someValues[j] = "c";
			}

			else if (getCharHashArray[i] == charHashArray[3]) {
				someValues[j] = "d";
			}

			else if (getCharHashArray[i] == charHashArray[4]) {
				someValues[j] = "e";
			}

			else if (getCharHashArray[i] == charHashArray[5]) {
				someValues[j] = "f";
			}

			else if (getCharHashArray[i] == charHashArray[6]) {
				someValues[j] = "g";
			}

			else if (getCharHashArray[i] == charHashArray[7]) {
				someValues[j] = "h";
			}

			else if (getCharHashArray[i] == charHashArray[8]) {
				someValues[j] = "i";
			}

			else if (getCharHashArray[i] == charHashArray[9]) {
				someValues[j] = "j";
			}

			else if (getCharHashArray[i] == charHashArray[10]) {
				someValues[j] = "k";
			}

			else if (getCharHashArray[i] == charHashArray[11]) {
				someValues[j] = "l";
			}

			else if (getCharHashArray[i] == charHashArray[12]) {
				someValues[j] = "m";
			}

			else if (getCharHashArray[i] == charHashArray[13]) {
				someValues[j] = "n";
			}

			else if (getCharHashArray[i] == charHashArray[14]) {
				someValues[j] = "o";
			}

			else if (getCharHashArray[i] == charHashArray[15]) {
				someValues[j] = "p";
			}

			else if (getCharHashArray[i] == charHashArray[16]) {
				someValues[j] = "q";
			}

			else if (getCharHashArray[i] == charHashArray[17]) {
				someValues[j] = "r";
			}

			else if (getCharHashArray[i] == charHashArray[18]) {
				someValues[j] = "s";
			}

			else if (getCharHashArray[i] == charHashArray[19]) {
				someValues[j] = "t";
			}

			else if (getCharHashArray[i] == charHashArray[20]) {
				someValues[j] = "u";
			}

			else if (getCharHashArray[i] == charHashArray[21]) {
				someValues[j] = "v";
			}

			else if (getCharHashArray[i] == charHashArray[22]) {
				someValues[j] = "w";
			}

			else if (getCharHashArray[i] == charHashArray[23]) {
				someValues[j] = "x";
			}

			else if (getCharHashArray[i] == charHashArray[24]) {
				someValues[j] = "y";
			}

			else if (getCharHashArray[i] == charHashArray[25]) {
				someValues[j] = "z";
			}

			else if (getCharHashArray[i] == charHashArray[26]) {
				someValues[j] = "0";
			}

			else if (getCharHashArray[i] == charHashArray[27]) {
				someValues[j] = "1";
			}

			else if (getCharHashArray[i] == charHashArray[28]) {
				someValues[j] = "2";
			}

			else if (getCharHashArray[i] == charHashArray[29]) {
				someValues[j] = "3";
			}

			else if (getCharHashArray[i] == charHashArray[30]) {
				someValues[j] = "4";
			}

			else if (getCharHashArray[i] == charHashArray[31]) {
				someValues[j] = "5";
			}

			else if (getCharHashArray[i] == charHashArray[32]) {
				someValues[j] = "6";
			}

			else if (getCharHashArray[i] == charHashArray[33]) {
				someValues[j] = "7";
			}

			else if (getCharHashArray[i] == charHashArray[34]) {
				someValues[j] = "8";
			}

			else if (getCharHashArray[i] == charHashArray[35]) {
				someValues[j] = "9";
			}


			else {

				throw 88;
			}

			// ++i and j, minus trackCount.

			++j;
			++i;
			--trackCharCount;
		}
		catch (int x) {

			system("cls");
			cout << "Encryption ERROR <CHAR>. Error code: " << x << "...(shutting down.)" << "\n";
			this_thread::sleep_for(chrono::seconds(3)); // exit?
			exit(0);
		}
	}

}

// Show our data "finalUserText"
void DisplayTextAsString() {

	for (int i = 0; i < 20; i++) {
		
		textBucket = someValues[i];
		finalUserText = finalUserText + textBucket;
		textBucket = "";

	}

	cout << "Your text is: " << finalUserText << "\n";
	system("pause");
	
}

// [CHARACTER] Resets
void charValueResets() {

	// string resets
	username = "";
	encryptedString = "";
	charEncryptData = "";
	textBucket = "";
	finalUserText = "";

	// bools resets
	charSignatureOK = false;

	// array resets

	for (int i = 0; i < 20; i++) 
		getCharHashArray[i] = "";

	for (int j = 0; j < 20; j++)
		someValues[j] = "";

	
}


int main() {

	while(1) {

		system("cls");

		// Get user input
		std::cout << "Enter your username: ";
		std::cin >> username;

		// check that the length is between 3-12
		if (username.length() < 3) {

			system("cls");
			std::cout << "Username must be 3-12 characters, exiting application...";
			std::this_thread::sleep_for(chrono::seconds(1));
			exit(0);

		}

		// we decrpyed here
		else if (username == "file") {

			// Get the string from file
			GetCharFromFile();

			// Strip the signature off the encrypted string
			checkCharSignature();

			// Check EACH "encrypted" string in the entire string
			charEncryptToArray();
			ArrayToText();
			
			// display appropriate text back to user
			DisplayTextAsString();

			// reset our values
			charValueResets();

		}

		// if username is acceptable
		else {

			// We convert our username to a char array
			StringToArray();

			// At this point our char array has values and index of 0 to n. We now Fix this input with some fixed encryption strings
			// Our function will check each element in char array, and assign apprpriate encryption string to our FINAL string
			PutEncryptStringsTogether();

			// we sign the encrupted data
			addSignatureToCharString();

			// we send our final string to a text file
			SendStringToFile();

			// Reset our Values
			charValueResets();
		}

		cout << "\n\n\n";
		system("pause");
	}

	system("pause");

}
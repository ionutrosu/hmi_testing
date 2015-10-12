/* EasyCASE V6.5 01/29/2015 18:01:26 */
/* EasyCASE O
If=horizontal
LevelNumbers=no
LineNumbers=no
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=System,,100,1,-13,0,700,0,0,0,0,0,0,1,2,1,34,96,96
PrinterFont=Courier,,100,1,-85,0,400,0,0,0,0,0,0,1,2,1,49,600,600
LastLevelId=3 */
/* EasyCASE ( 1 */
#include "Console.h"

/*
* Add here an include to your module header file.
*/
#include "TrainingModules/DaWa/DaWa.h"
#include "TrainingModules/AxMo/AxMo.h"
#include "TrainingModules/StKo/StKo.h"
#include "TrainingModules/CosGag/CosGag.h"
#include "TrainingModules/CriHog/CriHog.h"
#include "TrainingModules/EstUng/EstUng.h"
#include "TrainingModules/FrDu/FrDu.h"
#include "TrainingModules/GiuSab/GiuSab.h"
#include "TrainingModules/IngLis/IngLis.h"
#include "TrainingModules/NiBo/NiBo.h"
#include "TrainingModules/OliGab/OliGab.h"
#include "TrainingModules/PaDe/PaDe.h"
#include "TrainingModules/RonMus/RonMus.h"
#include "TrainingModules/StKo/StKo.h"
#include "TrainingModules/RadChe/RadChe.h"
#include "TrainingModules/SeKu/SeKu.h"
#include "TrainingModules/RoGo/RoGo.h"
#include "TrainingModules/ThGa/ThGa.h"
#include "TrainingModules/DeTh/DeTh.h"
#include "TrainingModules/StGr/StGr.h"
#include "TrainingModules/MirCer/MirCer.h"
#include "TrainingModules/MelCu/MelCu.h"
#include "TrainingModules/MarKir/MarKir.h"
#include "TrainingModules/LaPe/LaPe.h"
#include "TrainingModules/HaGuKo/HaGuKo.h"
#include "TrainingModules/FlHa/FlHa.h"
#include "TrainingModules/CalRod/CalRod.h"
#include "TrainingModules/BogVoi/BogVoi.h"
#include "TrainingModules/ValMil/ValMil.h"
#include "TrainingModules/JuKu/JuKu.h"
#include "TrainingModules/EmHe/EmHe.h"
#include "TrainingModules/RadTur/RadTur.h"
#include "TrainingModules/JanLac/JanLac.h"
#include "TrainingModules/MarHof/MarHof.h"
#include "TrainingModules/JoJa/JoJa.h"
#include "TrainingModules/ThoRav/ThoRav.h"
#include "TrainingModules/RoKo/Roco.h"
#include "TrainingModules/RoSi/RoSi.h"
#include "TrainingModules/TibMor/TibMor.h"
#include "TrainingModules/SteGhe/SteGhe.h"
#include "TrainingModules/RomBit/RomBit.h"
#include "TrainingModules/FenLee/FenLee.h"
#include "TrainingModules/VoRo/VoRo.h"
#include "TrainingModules/VRSZ/VRSZ.h"
#include "TrainingModules/INDC/INDC.h"
#include "TrainingModules/FloSch/FloSch.h"
#include "TrainingModules/SaDo/SaDo.h"
#include "TrainingModules/YiEGan/YiEGan.h"
#include "TrainingModules/FaSa/FaSa.h"
#include "TrainingModules/VasNik/VasNik.h"
#include "TrainingModules/ViSta/ViSta.h"
#include "TrainingModules/CarRob/CarRob.h"
#include "TrainingModules/ZhoWu/ZhoWu.h"
#include "TrainingModules/DomWei/DomWei.h"
#include "TrainingModules/DomWei/DomWei3.h"
#include "TrainingModules/AlTo/AlTo.h"
#include "TrainingModules/AdChi/AdChi.h"
#include "TrainingModules/AlGa/AlGa.h"
#include "TrainingModules/CaSe/CaSe.h"

/* EasyCASE ( 2
   vPrintAll */
/* EasyCASE F */
/*
* Add here a call to the _vPrintMe() function from your module.
*/
void vPrintAll()
   {
       CarRob_vPrintMe();
       StGr_vPrintMe();
       MirCer_vPrintMe();
       MelCu_vPrintMe();
       MarKir_vPrintMe();
       LaPe_vPrintMe();
       HaGuKo_vPrintMe();
       FlHa_vPrintMe();
       CalRod_vPrintMe();
       BogVoi_vPrintMe();
       ValMil_vPrintMe();
       CosGag_vPrintMe();
       CriHog_vPrintMe();
       EstUng_vPrintMe();
       FrDu_vPrintMe();
       RoSi_vPrintMe();
       GiuSab_vPrintMe();
       IngLis_vPrintMe();
       NiBo_vPrintMe();
       OliGab_vPrintMe();
       PaDe_vPrintMe();
       RonMus_vPrintMe();
       StKo_vPrintMe();
       RadChe_vPrintMe();
       SeKu_vPrintMe();
       RoGo_vPrintMe();
       ThGa_vPrintMe();
       DeTh_vPrintMe();
       AxMo_vPrintMe();
       MirMaz_vPrintMe();
       StGr_vPrintMe();
       MirCer_vPrintMe();
       JuKu_vPrintMe();
       EmHe_vPrintMe();        
       JanLac_vPrintMe();
       RadTur_vPrintMe();
       FloSch_vPrintMe();
       MarHof_vPrintMe();
       ThoRav_vPrintMe();
       JoJa_vPrintMe();
       TibMor_vPrintMe();
       SteGhe_vPrintMe();
       RomBit_vPrintMe();
       FenLee_vPrintMe();
       VoRo_vPrintMe();
       AdChi_vPrintMe();
       INDC_vPrintMe();
       VRSZ_vPrintMe();
       SaDo_vPrintMe();
       YiEGan_vPrintMe();
       FaSa_vPrintMe();
       VasNik_vPrintMe();
       VRSZ_vPrintMe();       
       YiEGan_vPrintMe();
       ViSta_vPrintMe();
       DaWa_vPrintMe();
       ZhoWu_vPrintMe();
       DomWei_vPrintMe();
       DomWei3_vPrintMe();
	   AlGa_vPrintMe();
	   RoKo_vPrintMe();
//<<<<<<< HEAD
	   //SoAv_vPrintMe();
//=======
//>>>>>>> TSR/SoAv
//=======
//>>>>>>> TSR/SoAv
       AlTo_vPrintMe();
	   CaSe_vPrintMe();

       /* End of Test */
   }
/* EasyCASE ) */
/* EasyCASE ( 3
   main */
/* EasyCASE F */
/*
* You do not need to change anything here.
*/
int main(int argc, char* argv[])
   {
   Console_vPrint("A word from each participant to this training:\n");
   vPrintAll();
   
   Console_vPrint("\nPress <Return> to exit\n");
   Console_vWaitForReturn();
   return 0;
   }
/* EasyCASE ) */
/* EasyCASE ) */

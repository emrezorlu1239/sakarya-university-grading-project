/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 01
**				ÖĞRENCİ ADI......:Emre Zorlu
**				ÖĞRENCİ NUMARASI.: B241210037
**				DERS GRUBU ......: A grubu
**   
****************************************************************************/



//Kütüphaneler
#include <iostream> //Giriş çıkış işlemleri için
#include <cstdlib>  // Rastgele sayı üretimi için
#include <cmath>    // Matematiksel işlemler için
#include <string>  // String işlemleri için
#include <ctime>   // Zaman fonksiyonu için
#include <iomanip> // Formatlı çıktı için
#include <sstream>   // ostringstream için


//Gerekli bütün namespaceler
using namespace std;



// Öğrenci yapısı
struct Ogrenci {
       
	    // Öğrenci bilgileri
	    string ad;
	    string soyisim;
        string sehir;
        string telefonNo;
        string dersAdi;
        int odev1;
        int odev2;
        int proje;
        int vize;
        int finalNot;
		float YiliciNot=0;
		string basariNot;
		string harfNot;


		// Yıl içi notunu hesaplayıp atama fonksiyonudur.
        float YiliciHesapla(int hesaplanacak_odev1, int hesaplanacak_odev2, int hesaplanacak_proje, int hesaplanacak_vize) {
             

               float yiliciNot = (hesaplanacak_odev1 * 0.1) +
                                 (hesaplanacak_odev2 * 0.1) + 
                                 (hesaplanacak_proje * 0.2) + 
                                 (hesaplanacak_vize * 0.6) ;
               return yiliciNot;

        }
    
	
	    // Başarı ve harf notunu belirleme fonksiyonudur. 
        string BasariNotu(float hesaplanacak_yiliciNot , float hesaplanacak_final) {
        
	         
			  // Toplam not hesaplama ve başarı notunu sayısal değerini atama
              string hesaplanacak_BasariNot;
		      float toplamNot =  (hesaplanacak_yiliciNot*0.5) + (hesaplanacak_final*0.5);
              
              ostringstream ss;
              ss << fixed << setprecision(2) << toplamNot; // 2 ondalık basamak
              hesaplanacak_BasariNot = ss.str();

			  // Finalden geçme durumu kontrol edilir ve geçememişse direkt FF verilir.
              if(hesaplanacak_final<40){
              
				    hesaplanacak_BasariNot += " - FF (kaldi)";
					harfNot = "FF";
              }
			  
			  //Fianalden geçmişse harf notu belirlenir.
              else {
                  
                        //AA alma notu şartı ve atama işlemi
                        if (toplamNot >= 90) {

                              hesaplanacak_BasariNot += " - AA";
							  harfNot = "AA";

                        }

						//BA alma notu şartı ve atama işlemi
                        else if (toplamNot >= 85) {

                              hesaplanacak_BasariNot+= " - BA";
							  harfNot = "BA";

                        }

						//BB alma notu şartı ve atama işlemi
                        else if (toplamNot >= 80) {

                              hesaplanacak_BasariNot += " - BB";
							  harfNot = "BB";

                        }

						//CB alma notu şartı ve atama işlemi
                        else if (toplamNot >= 75) {

                             hesaplanacak_BasariNot += " - CB";
							 harfNot = "CB";

                        }

						//CC alma notu şartı ve atama işlemi
                        else if (toplamNot >= 65) {

                            hesaplanacak_BasariNot += " - CC";
							harfNot = "CC";

                        }

						//DC alma notu şartı ve atama işlemi
                        else if (toplamNot >= 58) {

                             hesaplanacak_BasariNot += " - DC";
							 harfNot = "DC";

                        }

						//DD alma notu şartı ve atama işlemi
                        else if (toplamNot >= 50) {

                             hesaplanacak_BasariNot += " - DD";
							 harfNot = "DD";

                        }

						//FD alma notu şartı ve atama işlemi
                        else if (toplamNot >= 40) {

                             hesaplanacak_BasariNot += " - FD";
							 harfNot = "FD";

                        }

						//FF alma notu şartı ve atama işlemi
                        else {

                             hesaplanacak_BasariNot += " - FF (kaldi)";
							 harfNot = "FF";

				        }


		      }

			  return hesaplanacak_BasariNot;
	    }

};


int main()
{


	     // 100 kişilik sınıfı temsil eden dizi
         Ogrenci ProgramlamayaGiris_Sınıfı[100];


		 // Rastgele atanacak isimler
         string isimler[30] = {
              "Ahmet","Mehmet","Ayse","Fatma","Emre","Can","Bora","Deniz","Ece","Murat",
              "Gamze","Hakan","Leyla","Sinem","Kerem","Zeynep","Omer","Yusuf","Cem","Selin",
              "Burak","Ilayda","Serkan","Buse","Kadir","Merve","Onur","Asli","Tolga","Derya"
         };


		 // Rastgele atanacak soyisimler
         string soyisimler[30] = {
              "Yilmaz","Kaya","Demir","Sahin","Yildiz","Aydin","Arslan","Ozturk","Polat","Kilic",
              "Kurt","Celik","Gunes","Akar","Koc","Dogru","Erkan","Fidan","Kilicoglu","Orhan",
              "Poyraz","Sari","Tekin","Ulus","Vural","Yalcin","Zengin","Baran","Cinar","Dogan"
         };


		 // Rastgele atanacak şehirler
         string sehirler[30] = {
              "Sakarya","Istanbul","Ankara","Izmir","Bursa","Antalya","Konya","Kayseri","Eskisehir","Adana",
              "Trabzon","Gaziantep","Mersin","Diyarbakir","Malatya","Van","Mugla","Tekirdag","Balikesir","Sivas",
              "Erzurum","Aydin","Kocaeli","Sanliurfa","Kahramanmaras","Manisa","Hatay","Corum","Bolu","Ordu"
         };


         // Rastgele sayı üretimi için 
	     srand(time(0)); 


	     // Öğrenci bilgilerini atama döngüsü
         for (int i = 0; i < 100; i++) {

                // Rastgele isim seçimi
                 ProgramlamayaGiris_Sınıfı[i].ad = isimler[rand() % 30];


                // Rastgele soyisim  seçimi
                 ProgramlamayaGiris_Sınıfı[i].soyisim = soyisimler[rand() % 30];


                 // Rastgele şehir seçimi
                 ProgramlamayaGiris_Sınıfı[i].sehir = sehirler[rand() % 30];


                // Türkiye mobil numaralar 05 ile başlar ve 11 hanelidir.Bu değişkenle Öğrenci telefon numarası atıyacaz.
                 string telefonNo = "05";


                 // Rastgele telefon numarası oluşturma döngüsü
                 for (int j = 0; j < 9; j++) {
                        
                      // Her basamak için rastgele sayı üretimi ve telefonNo değişkenine basamak ekleme
					  telefonNo += to_string(rand() % 10); 
                    
				 }


                 // Telefon numarası atama
                 ProgramlamayaGiris_Sınıfı[i].telefonNo = telefonNo;

                 


                 // Ders adı atama
                 ProgramlamayaGiris_Sınıfı[i].dersAdi = "Programlamaya Giris";


                 //Bütün ödevlerin, projenin, vizenin ve finalin notlarını rastgele atama
                 ProgramlamayaGiris_Sınıfı[i].odev1 = rand() % 101;
                 ProgramlamayaGiris_Sınıfı[i].odev2 = rand() % 101;
                 ProgramlamayaGiris_Sınıfı[i].proje = rand() % 101;
                 ProgramlamayaGiris_Sınıfı[i].vize = rand() % 101;
                 ProgramlamayaGiris_Sınıfı[i].finalNot = rand() % 101;


                 // Yıl içi notunu hesaplama ve atama
                 ProgramlamayaGiris_Sınıfı[i].YiliciNot = ProgramlamayaGiris_Sınıfı[i].YiliciHesapla(
                 ProgramlamayaGiris_Sınıfı[i].odev1,
                 ProgramlamayaGiris_Sınıfı[i].odev2,
                 ProgramlamayaGiris_Sınıfı[i].proje,
                 ProgramlamayaGiris_Sınıfı[i].vize);


                //Başarı notunu ve harf notunu belirleme ve atama
                 ProgramlamayaGiris_Sınıfı[i].basariNot = ProgramlamayaGiris_Sınıfı[i].BasariNotu(
                 ProgramlamayaGiris_Sınıfı[i].YiliciNot,
                 ProgramlamayaGiris_Sınıfı[i].finalNot);


         }
         

	     // Sınıf ortalamasını hesaplama 
         float sinifToplamNot = 0.0;
         for (int i = 0; i < 100; i++) {
                
                float ogrenciToplamNot = (ProgramlamayaGiris_Sınıfı[i].YiliciNot * 0.5) + (ProgramlamayaGiris_Sınıfı[i].finalNot * 0.5);
                sinifToplamNot += ogrenciToplamNot;

         }
		 float sinifOrtalama = sinifToplamNot / 100.0;

		 //Standart sapma hesaplama için ilk değişken tanımlıyoruz
         float toplamKareFark = 0.0;

		 // Standart sapma hesaplama
         for (int i = 0; i < 100; i++) {
                
                float ogrenciToplamNot = (ProgramlamayaGiris_Sınıfı[i].YiliciNot * 0.5) + (ProgramlamayaGiris_Sınıfı[i].finalNot * 0.5);
                float fark = ogrenciToplamNot - sinifOrtalama;
                toplamKareFark += fark * fark;

		 }
		 float standartSapma = sqrt(toplamKareFark / 100.0);
             

         //Tüm harflerin kaç tane olduğunu bulmak için  değişkenler
		 int aa_sayac = 0, ba_sayac = 0, bb_sayac = 0, cb_sayac = 0, cc_sayac = 0, dc_sayac = 0, dd_sayac = 0, fd_sayac = 0, ff_sayac = 0;
		 
         
         //Harf notu yüzdelik dağılımı hesaplama
         for(int i=0;i<100;i++){

			

			 //AA not sayısını sayma
             if (ProgramlamayaGiris_Sınıfı[i].harfNot == "AA") {
                
                 aa_sayac++;

             }

             //BA not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "BA") {
                
                 ba_sayac++;

			 }


             //BB not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "BB") {
                
                 bb_sayac++;

			 }


             //CB not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "CB") {
                
                 cb_sayac++;

             }


             //CC not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "CC") {
                
                 cc_sayac++;

             }


             //DC not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "DC") {
                
                 dc_sayac++;

             }


             //DD not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "DD") {
                
                 dd_sayac++;

             }


             //FD not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "FD") {
                
                 fd_sayac++;

             }


            //FF not sayısını sayma
             else if (ProgramlamayaGiris_Sınıfı[i].harfNot == "FF") {
                
                 ff_sayac++;

			 }
             

		 }  


		 //Sınıf ortalamasını, standart sapmayı ve harf notu dağılımını ekrana yazdırma
         cout << "Sinif Ortalamasi: " << sinifOrtalama << endl;
		 cout << "" << endl;
		 cout << "-------------------------" << endl;
		 cout << "" << endl;
         cout << "Standart Sapma: " << standartSapma << endl;
		 cout << "" << endl;
         

		 //Harf notu dağılımı yüzdelik olarak ekrana yazdırma
         cout << "Harf Notu Dagilimi :" << endl;
         cout << "AA: %" << (aa_sayac / 100.0) * 100  << endl;
         cout << "BA: %" << (ba_sayac / 100.0) * 100  << endl;
         cout << "BB: %" << (bb_sayac / 100.0) * 100  << endl;
         cout << "CB: %" << (cb_sayac / 100.0) * 100  << endl;
         cout << "CC: %" << (cc_sayac / 100.0) * 100  << endl;
         cout << "DC: %" << (dc_sayac / 100.0) * 100  << endl;
         cout << "DD: %" << (dd_sayac / 100.0) * 100  << endl;
         cout << "FD: %" << (fd_sayac / 100.0) * 100  << endl;
		 cout << "FF: %" << (ff_sayac / 100.0) * 100  << endl;
		 cout << "-------------------------" << endl;
		 cout << "" << endl;


         // Listeyi göstermeden önce bekletme
         cout << "\nOgrenci listesi hazir. Goruntulemek icin ENTER'a basin...";
         cin.get(); // buffer temizleme
         cin.get(); // gerçek durdurma

  
         // Öğrencileri toplam nota göre (yüksekten düşüğe) sıralama 
         for (int i = 0; i < 100 - 1; i++) {

               int enBuyukNo = i;

			   // Kalan dizide en büyük notu bulma
               for (int j = i + 1; j < 100; j++) {

                          float not_i = (ProgramlamayaGiris_Sınıfı[enBuyukNo].YiliciNot * 0.5) +
                                      (ProgramlamayaGiris_Sınıfı[enBuyukNo].finalNot * 0.5);

                          float not_j = (ProgramlamayaGiris_Sınıfı[j].YiliciNot * 0.5) +
                                      (ProgramlamayaGiris_Sınıfı[j].finalNot * 0.5);


                           // Daha büyük bir not bulunduysa güncelle
                           if (not_j > not_i) {
                            
                               enBuyukNo = j;
                 
                           }
               }


             // Yer değiştirme
             if (enBuyukNo != i) {
                 
                      Ogrenci sirasi = ProgramlamayaGiris_Sınıfı[i];
                      ProgramlamayaGiris_Sınıfı[i] = ProgramlamayaGiris_Sınıfı[enBuyukNo];
                      ProgramlamayaGiris_Sınıfı[enBuyukNo] = sirasi;

             }


         }


		 // Sınıf listesi ve bütün özelliklerin ekrana yazdırılması
         for (int i = 0; i < 100; i++) {
             cout << "Ogrenci " << i + 1 << ": " << endl;
             cout << "Ad: " << ProgramlamayaGiris_Sınıfı[i].ad << endl;
             cout << "Soyisim: " << ProgramlamayaGiris_Sınıfı[i].soyisim << endl;
             cout << "Sehir: " << ProgramlamayaGiris_Sınıfı[i].sehir << endl;
             cout << "Telefon No: " << ProgramlamayaGiris_Sınıfı[i].telefonNo << endl;
             cout << "Ders Adi: " << ProgramlamayaGiris_Sınıfı[i].dersAdi << endl;
             cout << "Odev 1 Notu: " << ProgramlamayaGiris_Sınıfı[i].odev1 << endl;
             cout << "Odev 2 Notu: " << ProgramlamayaGiris_Sınıfı[i].odev2 << endl;
             cout << "Proje Notu: " << ProgramlamayaGiris_Sınıfı[i].proje << endl;
             cout << "Vize Notu: " << ProgramlamayaGiris_Sınıfı[i].vize << endl;
             cout << "Final Notu: " << ProgramlamayaGiris_Sınıfı[i].finalNot << endl;
             cout << "Yilici Notu: " << ProgramlamayaGiris_Sınıfı[i].YiliciNot << endl;
             cout << "Basari Notu: " << ProgramlamayaGiris_Sınıfı[i].basariNot << endl;
             cout << "-----------------------------"<<endl;
         }
         
       
         //Program bitiyor
		 return 0;
}



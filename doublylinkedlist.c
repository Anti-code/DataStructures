#include<stdio.h>
#include<stdlib.h>

//Çift yönlü bağlı liste için temel veri yapısı
struct Eleman  {
	int data; // Elemanın tutacağı değer
	struct Eleman* sonraki; // Sonraki elemanın bağlanacağı değer
	struct Eleman* onceki; // Önceki elemanın bağlanacağı değer
};

int listSize=0;
struct Eleman* root; // Başlangıç düğümü için referans

//Yeni düğüm oluşturur
struct Eleman* yeniElemanOlustur(int deger) {
	struct Eleman* yeniEleman= (struct Eleman*)malloc(sizeof(struct Eleman)); //Yeni eleman için bellekten yer ayır
	
	yeniEleman->data = deger; // Elemana değer ata
	yeniEleman->onceki = NULL; //Yeni oluşturulacak elemanın öncesine ve sonrasina bağlanacak elemanlar olamaz.
	yeniEleman->sonraki = NULL;
	
	listSize++;
	return yeniEleman;
}
//Elemanları sırayla yazdırır
void yazdir() {
	
	struct Eleman* geciciEleman = root; // Listeyi dolaşmak için geçici eleman 
	
	printf("\nListe:  \t");
	
	while(geciciEleman) {				//Sırada eleman olduğu sürece
		printf("(%d)",geciciEleman->data);	// Elemanın verisini yaz
		if(geciciEleman->sonraki)			 
			printf("__");
		geciciEleman = geciciEleman->sonraki;	// Sonraki elemanı yazdırılacak eleman yap
	}
	printf("\n");
}
//Bağlı listenin başına eleman ekler
void listeBasinaEkle(int deger) {
	struct Eleman* yeniEleman = yeniElemanOlustur(deger); // Eklenecek elemanı oluştur
	
	if(root == NULL) { 	// Hiç eleman yoksa
		root = yeniEleman; //  yeni elemanı baş eleman yap
		printf("%d ilk eleman olarak eklendi\n",yeniEleman->data);
		return;
	}
	
	root->onceki = yeniEleman;	// Listenin baş elemanından önceki eleman olarak yeni elemanı göster
	yeniEleman->sonraki = root; // Yeni elemandan sonraki eleman olarak baş elemanı göster
	root = yeniEleman;// yeni elemanı baş eleman yap
	
	printf("(%d) liste basina eklendi\n",root->data);
}
void listeBasindanSil(){ 
	
	struct Eleman* geciciEleman=root; // Listede dolaşmak için yeni bir eleman oluştur
	
	while(geciciEleman->onceki)              // Önceki eleman olduğu sürece
		geciciEleman=geciciEleman->onceki;	// geçici elemanı önceki eleman yap. Böylece listenin ilk elemanı bulunur
		
	root=geciciEleman->sonraki;				// Listenin ilk elemanı olarak en baştaki elemandan bir sonraki elemanı seç
	root->onceki=NULL;						// Listenin en başındaki elemandan önce bir eleman olamaz
	
	puts("Liste basindaki eleman silindi");
	free(geciciEleman);						// Eleman hafızadan silinir
}

//Bağlı listenin sonuna eleman ekler
void listeSonunaEkle(int deger) {
	struct Eleman* geciciEleman = root;  // Listede dolaşmak için yeni bir eleman oluştur
	struct Eleman* yeniEleman = yeniElemanOlustur(deger);  // Eklenecek elemanı oluştur
	
	if(root == NULL) {  //   Hiç eleman yoksa
		root = yeniEleman; //  yeni elemanı baş eleman yap
		printf("%d ilk eleman olarak eklendi\n",yeniEleman->data);
		return;
	}
	
	while(geciciEleman->sonraki) 
		geciciEleman = geciciEleman->sonraki; // Listenin son elemanına git
		
	geciciEleman->sonraki = yeniEleman;		// Yeni elemanı listenin sonundaki elemana bağla
	yeniEleman->onceki = geciciEleman;
	
	printf("%d liste sonuna eklendi\n",yeniEleman->data);
}

void listeSonundanSil(){
	struct Eleman* geciciEleman=root; // Listede dolaşmak için yeni bir eleman oluştur
	
	while(geciciEleman->sonraki)	
		geciciEleman=geciciEleman->sonraki; // Listenin son elemanına git
		
	geciciEleman->onceki->sonraki=NULL;   // Son elemanın bir öncekiyle bağlantısını kes
	
	puts("Liste sonundaki eleman silindi");
	free(geciciEleman);		// Elemanı hafızadan sil
}

void listeArasinaEkle(){
	yazdir();
	
	int index, data, count=0, i;
  
	printf("(EKLE) Data:");
	scanf("%d",&data);		// Elemanın ekleneceği aralık ve elemanın değeri
	printf("(EKLE) Index:");
	scanf("%d",&index);
	
	struct Eleman* geciciEleman=root; // Listede dolaşmak için geçici eleman
	struct Eleman* yeniEleman=yeniElemanOlustur(data);	// Listeye eklenecek elemanı oluştur
	
	if(index==1){
		listeBasinaEkle(data); return;}
		
	else if(index>listSize){
		puts("(HATA) Listedeki eleman sayisi silmek istediginiz elemanin indexinden daha az.");return;}
		
	else{
		for(i=2;i<index;i++)		// Eklenecek elemanın indexine kadar git
			geciciEleman=geciciEleman->sonraki;
			
		yeniEleman->sonraki=geciciEleman->sonraki; // Yeni elemandan sonraki elemanı indexle belirlenen elemandan sonraki eleman yap(1. bağ)
		geciciEleman->sonraki->onceki=yeniEleman; // Yeni elemandan sonra gelen elemanın öncesindeki elemanı yeni eleman yap   (2. bağ)
		yeniEleman->onceki=geciciEleman;		// Yeni elemandan önceki elemanı indexteki eleman yap (1. bağ)
		geciciEleman->sonraki=yeniEleman;		// Indexteki elemandan sonraki elemanı yeni eleman yap(2.bağ)
		
		
		printf("(%d) %d. indexe eklendi.\n",yeniEleman->data,index);	
		}
	}
		
	
	
	
void listeArasindanSil(){
	yazdir();
	
	int count=1,index, i;
	printf("(Sil) Index:");	// Silinecek elemanın indexi
	scanf("%d",&index);
	
	struct Eleman* geciciEleman=root; // Listeyi dolaşmak için geçici eleman oluştur
	
	if(index==1){
		listeBasindanSil();return;}
		
	else if(index>listSize){
		puts("(HATA) Listedeki eleman sayisi silmek istediginiz elemanin indexinden daha az.");return;}
		
	else{
		for(i=1;i<index;i++)		// Silinecek elemanın indexine kadar listede ilerle
			geciciEleman=geciciEleman->sonraki;
			
		geciciEleman->sonraki->onceki=geciciEleman->onceki; // indexteki elemanın sonrasindaki elemanı öncekine bağla(1. bağ)
		geciciEleman->onceki->sonraki=geciciEleman->sonraki;//indexteki elemanın öncesindeki elemanı sonrakine bağla(1. bağ)
		
		printf("(%d) Silindi\n",geciciEleman->data);
		
		free(geciciEleman);	// elemanı hafızadan sil
		}
	}
	
	



//Elemanları tersten sırayla yazdırır 
void terstenYazdir() {
	
	struct Eleman* geciciEleman = root; // Listeyi dolaşmak için geçici eleman
	
	while(geciciEleman->sonraki) {	// Sırada eleman olduğu sürece
		geciciEleman = geciciEleman->sonraki;	// Bir sonraki elemana git. Listenin sonuna gider.
	}
	
	printf("\nTersten Liste:  ");
	
	while(geciciEleman) {		// Listede eleman olduğu sürece
		printf("(%d)",geciciEleman->data); // Elemanın değerini yazdır
		if(geciciEleman->onceki)			
			printf("__");
		geciciEleman = geciciEleman->onceki; // Bir öncesindeki elemanı yazdırılacak eleman yap
	}
	printf("\n");
}

int main() {
	int i;
	root = NULL; // Boş liste için ilk referans.,
	int sayiListesi[10]={1,31,51,4,24,6,81,5,9,32}; //10 elemanlı dizi oluştur
	
	for(i=0;i<5;i++)
		listeSonunaEkle(sayiListesi[i]);	// 5 tanesini listenin sonundan ekle
	for(i=5;i<10;i++)
		listeBasinaEkle(sayiListesi[i]);	// 5 tanesini listenin başından ekle
	
	yazdir();
	terstenYazdir();
	
	for(i=0;i<3;i++)
		listeArasindanSil();		
	for(i=0;i<3;i++)
		listeArasinaEkle();
	yazdir();
}

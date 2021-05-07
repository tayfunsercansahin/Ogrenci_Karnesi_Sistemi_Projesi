#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ogrenci{
private:
    string isim;
    int numara;
    float ingilizce, tarih, cografya, fen, matematik, ortalama;
public:
    void veri_ekle(string is,int nu,float in,float ta,float co,float fe,float ma){
        isim=is;
        numara=nu;
        ingilizce=in;
        tarih=ta;
        cografya=co;
        fen=fe;
        matematik=ma;
        ortalama=(ingilizce+tarih+cografya+fen+matematik)/5;
    }

    int numara_al(){
        return numara;
    }

    void rapor(){
        cout<<"OGRENCI RAPORU"<<endl;
        cout<<"=============="<<endl;
        cout<<"Isim: "<<isim<<endl;
        cout<<"Numara: "<<numara<<endl;
        cout<<"Ingilizce Notu: "<<ingilizce<<endl;
        cout<<"Tarih Notu: "<<tarih<<endl;
        cout<<"Cografya Notu: "<<cografya<<endl;
        cout<<"Fen Notu: "<<fen<<endl;
        cout<<"Matematik Notu: "<<matematik<<endl;
        cout<<"Ortalama Not: "<<ortalama<<endl;
        cout<<"Not Ortalamasi: "<<ortalama/10<<endl;
    }
};

vector<ogrenci>veriler;
int verilerin_boyutu;

void rapor_yaz(int numara){
    for(int i=0;i<verilerin_boyutu;i++){
        if(veriler[i].numara_al()==numara){
            veriler[i].rapor();
            return;
        }
    }

    cout<<"Girilen Numara Mevcut Degil"<<endl;
}

void verileri_yeniden_boyutlandir(){
    veriler.resize(verilerin_boyutu);
}

void istatistikleri_goster(){
    cout<<"Boyut: "<<verilerin_boyutu<<endl;
    cout<<"Ogrenci Listesi(Numara): "<<endl;

    if(verilerin_boyutu==0){
        cout<<"Veritabani Bos"<<endl;
        return;
    }

    for(int i=0;i<verilerin_boyutu;i++){
        cout<<veriler[i].numara_al()+" ";
    }
}

void ekle(){
    string isim;
    int numara;
    float ingilizce, tarih, cografya, fen, matematik;

    cout<<"Lutfen Ogrenci Detaylarini Giriniz: "<<endl;
    cout<<"Isim: "<<endl;
    cin.ignore();
    getline(cin,isim);
    cout<<"Numara: "<<endl;
    cin>>numara;
    cout<<"Sirasiyla Ingilizce, Tarih, Cografya, Fen ve Matematik Notlarini Giriniz: "<<endl;
    cin>>ingilizce>>tarih>>cografya>>fen>>matematik;
    cout<<"Veritabanina Eklenen Ogrenci Verileri"<<endl;
    /*cout<<"Ingilizce: "<<ingilizce<<endl;
    cout<<"Tarih: "<<tarih<<endl;
    cout<<"Cografya: "<<cografya<<endl;
    cout<<"Fen: "<<fen<<endl;
    cout<<"Matematik: "<<matematik<<endl;*/

    verilerin_boyutu++;
    verileri_yeniden_boyutlandir();
    veriler[verilerin_boyutu-1].veri_ekle(isim,numara,ingilizce,tarih,cografya,fen,matematik);
}

void sil(int numara){
    for(int i=0;i<verilerin_boyutu;i++){
        if(veriler[i].numara_al()==numara){
            veriler.erase(veriler.begin()+i);
            cout<<numara<<" Numarali Ogrenci Veritabanindan Kaldirildi"<<endl;
            verilerin_boyutu--;
            return;
        }
    }

    cout<<"Girilen "<<numara<<" Numara Mevcut Degil"<<endl;
}

int main(){
    int tercih, numara;
    cout<<"Ogrenci Raporu Veritabani Yonetimi"<<endl;
    cout<<"=================================="<<endl;

    do{
        cout<<"1 -> Yeni Ogrenci Verilerini Ekle"<<endl;
        cout<<"2 -> Ogrenci Verilerini Sil"<<endl;
        cout<<"3 -> Raporu Yazdir"<<endl;
        cout<<"4 -> Veritabani Istatistikleri"<<endl;
        cout<<"0 -> Cikis"<<endl;
        cout<<"=================================="<<endl;
        cout<<"Tercihinizi Giriniz: "<<endl;
        cin>>tercih;

        switch(tercih){
            case 1:
                ekle();
                break;
            case 2:
                cout<<"Numara: "<<endl;
                cin>>numara;
                sil(numara);
                break;
            case 3:
                cout<<"Numara: "<<endl;
                cin>>numara;
                rapor_yaz(numara);
                break;
            case 4:
                istatistikleri_goster();
                break;
            case 0:
                break;
            default:
                cout<<"Gecersiz Tercih"<<endl;
                break;
        }
    }while(tercih);

    return 0;
}






















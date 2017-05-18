#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//metinsel ifadeyi kucuk karaktere cevirir
string makeLower(string text) {
    transform(text.begin(), text.end(), text.begin(),(int (*)(int))tolower);

    return text;
}

//istenilen dosyaya istenilen deger uzerine eklenerek yazilir
void writeToFile(string path , string *val) {
    ofstream myfile;
    myfile.open (path.c_str() , ios_base::app);
    myfile <<val<<endl;
    myfile.close();
}

int main() {

    char data[1000];
    string fileName = "";//dosya yolu
    string searchVal = "";//aranacak olan deger
    string searchType = "";//arama tipi
    int counter = 0;//bulunan eleman sayisi

    //Klavyeden degerler okunur
    cout<<"Dosya yolu : ";
    cin>>fileName;
    cout<<"Aranacak deger : ";
    cin>>searchVal;
    cout<<"Arama turu : ";
    cin>>searchType;

    //Validasyon islemleri yapilir
    if(fileName != "file.dat" || searchVal.length() == 0 || (searchType != "dosya" && searchType != "sessiz" && searchType != "ekran" ) ) {
        cout<<"Parametre hatasi olustu. Lutfen kullanim kilavuzunu okuyun ve parametreleri eksiksiz ve dogru bir sekilde giriniz!";
    } else {
        // eger herhangi bir eksik yoksa asagidsaki islemler yapilir

        //Dat dosyasi okunur
        ifstream infile;
        infile.open("file.dat");

        infile >> data;
        cout<<endl<<"Adresler"<<endl;
        while(infile) {
            infile>>data;//dat dosyasi satir satir okunur
            string val = makeLower(data);
            searchVal = makeLower(searchVal);//her bir eleman buyukten kucuge cevrilir
            if(val == searchVal) {// aranan deger sistemde mevcutsa
                counter++;//eleman sayisi 1 arttirilir
                string * pointer;//
                pointer = &val;// bulunan elamanin adres degeri saklanir
                if(searchType == "dosya" || searchType == "sessiz") {
                    writeToFile("result.txt" , pointer);// eger arama tipi ekrandan farkliysa sonuclar dosyaya yazilir.
                }
                cout<<pointer;
            }
        }
        if(counter>0) {//Eger sonuc bulunduysa
            cout<<endl<<counter<<" adet sonuc bulundu "<<endl<<endl;
            if(searchType == "dosya") {
                cout<<"Sonuclar result.txt dosyasina yazildi";
            }
        } else {// bulunmadiysa
            cout<<"Sonuc bulunamadi";
        }
    }
    system("PAUSE");
    return 0;
}

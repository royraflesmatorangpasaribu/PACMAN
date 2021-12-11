/* Program Game Pacman, dibuat oleh :
   - Fathimah Abiyyi Khairunnisa (2117051088)
   - Jihan Haya Mufialdo (2117051095)
   - Roy Rafles Matorang Pasaribu (2117051058)
   
 * Pada tanggal : 22 November 2021 - 9 Desember 2021
 
 * Untuk mengkompilasi dan menjalankan program ini
   silahkan menggunakan windows untuk hasil yang maksimal,
   atau menggunakan IDE : dev-c++
*/ 

#include <iostream>             // untuk menampilkan perintah cout, cin, endl.
#include <conio.h>              // untuk menampilkan fungsi getche().
#include <ncurses\ncurses.h>    // untuk menampilkan perintah mvprintw, scanw.
#include <windows.h>            // untuk menampilkan fungsi Sleep().
#include <string.h>             // untuk menampilkan fungsi strupr().

using namespace std;

char pemain[50];	// menyimpan data variabel pemain.		

// fungsi 	
void judul();  
void menu();
void lagi();
void map1();
void map2();

// fungsi utama
int main(){	
	
	menu();			// memanggil prosedur fungsi menu.	
	
	return 0;		// karena menggunakan fungsi main.
}

void judul(){
	
	/* merupakan fungsi judul yang akan ditampilkan dan dipanggil berkali-kali pada menu */
	
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t      ~ SELAMAT DATANG PADA PERMAINAN ~\n\n";
	cout << "\t\t\t\t-------------------------------------------------------------\n";
	cout << "\t\t\t\t|         ______ _____ ______ ___  ____ _____ ____  __      |\n";
	cout << "\t\t\t\t|        /  _  // _  //  ___//   |/   // _  //    |/ /      |\n";
	cout << "\t\t\t\t|       /  ___//    //  /__ /  /|_/  //    //  /|   /       |\n";
	cout << "\t\t\t\t|      /__/   /_//_/ \\____//__/  /__//_//_//__/ |__/        |\n";
	cout << "\t\t\t\t|                                                           |\n";
	cout << "\t\t\t\t|                 B  Y  :  J  I  F  A  R  O                 |\n";
	cout << "\t\t\t\t-------------------------------------------------------------\n";
	
}

void loading(){
	
	// menginisialisasi layar untuk penggunaan ncurses.
	initscr();
	
	mvprintw(12,55, "Loading");
	
	mvprintw(13,48, "------------------------");
	mvprintw(14,48, "|                      |");
	mvprintw(15,48, "------------------------");
			
	for(int n=1; n<12; n++){	 
		for(int i=1; i<5; i++){
			mvprintw(12,61+i, ".");
			refresh();
			Sleep(100);				   // untuk mendelay layar selama 0,1 detik.
		}	
		mvprintw(14,47+n+n, "]]");
		refresh();
		Sleep(300);					   // untuk mendelay layar selama 0,3 detik.
	}
	
	refresh();
	
	// menutup layar mode ncurses.
	endwin();    
}

void menu(){
	
	// MULAI
	judul();    		// memanggil fungsi judul.
	
	cout << "\n\t\t\t\t\t\t   Ingin Memulai Permainan?\n";
	cout << "\t\t\t\t\t\t        [ Klik Enter ]\n\n\n\n\n\n\n\n\n\n\n";
	
	
	system("pause");	// untuk menahan layar pada program yang sedang dijalankan.
	system("cls");		// untuk membersihkan layar pada program yang akan dijalankan.
	
	//LOADING
	loading();			// memanggil fungsi loading.
	
	//NAMA
	judul();
	
	cout << "\n\t\t\t\t\t\t  Masukan Nama Anda : ";
	cin >> pemain;		// memasukkan data pemain.

	system("cls");
	
	//TINGKAT
	judul();
	
	int level;			// deklarasi variabel level.
	
	cout << "\n\t\t\t\t\t\t\tPilih Level : \n";
	cout << "\t\t\t\t\t\t\t1. Mudah\n";
	cout << "\t\t\t\t\t\t\t2. Sulit\n";
	cout << "\t\t\t\t\t\t\t-> ";
	cin >> level;		// memasukkan pilihan level.
	
	switch(level){
		case 1 :
			map1();		// jika memilih level 1, maka akan memanggil prosedur fungsi map1.
			break;		// menghentikan eksekusi switch apabila ada satu kondisi yang terpenuhi.		
		case 2 :
			map2();		// jika memilih level 2, maka akan memanggil prosedur fungsi map2.
			break;		// menghentikan eksekusi switch apabila ada satu kondisi yang terpenuhi.
		default :
			char pilihan;
			cout << "\n\t\t\t\t\t\t  !! INPUT TIDAK SESUAI !!\n";
			cout << "\t\t\t\t\t     ingin tetap pada permainan (y/t) ? ";
			cin >> pilihan;
				if(pilihan=='y'||pilihan=='Y'){
					main();
				}else{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    TERIMA KASIH SUDAH MEMAINKAN GAME PACMAN by JIFARO\n\n\n";
					cout << "\t\t\t\t\t\t          /\\_/\\" << endl;
					cout << "\t\t\t\t\t\t         (  >.<)" << endl;
					cout << "\t\t\t\t\t\t         / )[bye!]" << endl;
					cout << "\n\n\n\n\n\n\n\n";
				}
	}
}

void lagi(){
	
	char pilih;
	
	cout << "\n\n\n\n\n\n\t\t\t\t\t\tINGIN BERMAIN KEMBALI (y/t) ? ";
	cin >> pilih;
	
	if(pilih=='y'||pilih=='Y'){
		main();
	}else{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    TERIMA KASIH SUDAH MEMAINKAN GAME PACMAN by JIFARO\n\n\n";
		cout << "\t\t\t\t\t\t          /\\_/\\" << endl;
		cout << "\t\t\t\t\t\t         (  >.<)" << endl;
		cout << "\t\t\t\t\t\t         / )[bye!]" << endl;
		cout << "\n\n\n\n\n\n\n\n";
	}
	
}

void map1(){
	
	system("cls");
	
	cout << "\n Instruksi : \n";
	cout << " 1. Gunakan tombol aswd untuk bergerak\n";
	cout << " 2. Makan titik (.) untuk mendapatkan poin\n";
	cout << " 3. Hindari pagar (#)\n";
	cout << " 4. Skor minimal 50 untuk menang\n";
	cout << "\n\n [ Klik Enter ]";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
	system("pause");
	system("cls");
	
	string map[17][20];		// array 2 dimensi untuk menyimpan koordinat map.
	int x,y;				// x menyimpan koordinat baris, y menyimpan koordinat kolom (pada array).
	int a=15,b=18;			// koordinat awal pacman.
	int score=0;			// mengembalikan nilai score secara default.
	char move;				// deklarasi variabel move.
	
// BENTUK MAP 1
	
	// menyimpan koordinat dinding dan rintangan pada map.
 	for(x=0;x<17;x++){
		for(y=0;y<20;y++){	
			if(x==0 || x==16){ 
				map[x][y]="#"; 
			}
			else if(y==0  || y==19){ 
				map[x][y]="#"; 
			}
			else if(x==1  && y>5  && y<9){ 
				map[x][y]="#"; 
			}
			else if(x==2  && y>1  && y<5){ 
				map[x][y]="#"; 
			}
			else if(x==3  && y==1){ 
				map[x][y]="#"; 
			}
			else if(x==3  && y==5){ 
				map[x][y]="#"; 
			}
			else if(x==4  && y>14 && y<18){ 
				map[x][y]="#"; 
			}
			else if(x==5  && y>0  && y<5){ 
				map[x][y]="#"; 
			}
			else if(x==5  && y>5  && y<10){ 
				map[x][y]="#"; 
			}
			else if(x==7  && y>13 && y<20){ 
				map[x][y]="#"; 
			}
			else if(x==8  && y>5  && y<13){ 
				map[x][y]="#";	
			}
			else if(x==10 && y>3  && y<10){ 
				map[x][y]="#"; 
			}
			else if(x==10 && y>13 && y<18){ 
				map[x][y]="#"; 
			}
			else if(x==11 && y==13){ 
				map[x][y]="#"; 
			}
			else if(x==12 && y==12){ 
				map[x][y]="#"; 
			}
			else if(x==13 && y==11){ 
				map[x][y]="#"; 
			}
			else if(x==13 && y>14 && y<20){ 
				map[x][y]="#"; 
			}
			else if(x==14 && y>2  && y<8){ 
				map[x][y]="#"; 
			}
			else if(x==15 && y==1){ 
				map[x][y]="#"; 
			}
			else if(x==15 && y==15){ 
				map[x][y]="#"; 
			}
			else if(y==2 && x>9 && x<15){ 
				map[x][y]="#"; 
			}
			else if(y==5 && x>6 && x<9){ 
				map[x][y]="#"; 
			}
			else if(y==7 && x>11 && x<14){ 
				map[x][y]="#"; 
			}
			else if(y==12 && x>2 && x<8){ 
				map[x][y]="#"; 
			}
			else{
				map[1][1]="0";	// koordinat finish.
				map[x][y]=".";	// koordinat titik/makanan.
			}
		}		
	}
	
// PACMAN DAN SKOR
	
	// koordinat pacman.
	map[a][b]="@";
	
	cout << pemain << " : " << score;	// menampilkan nama pemain dan score yang diperoleh.
	cout << "\n\n";
	
	// menampilkan map.
	for(x=0;x<17;x++){
		for(y=0;y<20;y++){
			cout << map [x][y] << " ";	
		}
		cout << endl;
	}
	
	while(true){
		cout << "\n(a,s,w,d) : ";
			/* tombol yang digunakan untuk menggerakkan pacman
			   a = kiri
			   d = kanan
			   w = atas
			   s = bawah
			*/
		move = getche();
			// tombol yang ditekan akan langsung ditampilkan dan dijalankan tanpa harus mengklik enter.
		
		if(move=='s'){
			a++;				 // koordinat baris akan bertambah.
			if(a>0){			 // ketika a>0 (dinding), maka karakter titik(.)
				map[a-1][b]=" "; // pada posisi awal akan dirubah menjadi kosong( ).
			}
		}
		else if(move=='w'){
			a--;				 // koordinat baris akan berkurang.
			if(a>0){			 // ketika a>0 (dinding), maka karakter titik(.)
				map[a+1][b]=" "; // pada posisi awal akan dirubah menjadi kosong( ).
			}
		}
		else if(move=='a'){		 
			b--;				 // koordinat kolom akan berkurang.
			if(b>0){			 // ketika b>0 (dinding), maka karakter titik(.)
				map[a][b+1]=" "; // pada posisi awal akan dirubah menjadi kosong( ).
			}
		}
		else if(move=='d'){
			b++;				 // koordinat kolom akan bertambah.
			if(b>0){			 // ketika b>0 (dinding), maka karakter titik(.)
				map[a][b-1]=" "; // pada posisi awal akan dirubah menjadi kosong( ).
			}
		}
		
		if(map[a][b]=="."){ 	// ketika koordinat pacman = titik(.), maka score bertambah 1.
			score+=1;
		}
		
		if(map[a][b]=="#"){ // ketika koordinat pacman = pagar/rintangan, maka pemain kalah.
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t\t\t         " << strupr(pemain) << " KALAH"; 	// strupt = mengkapitalkan nama pemain.
			cout << "\n\n\t\t\t\t\t\t         Score : " << score;
			lagi();			// memanggil prosedur fungsi lagi.
			break;	
		}
		
		if(map[a][b]=="0"&&score>=50){  //ketika koordinat pacman = 0, dan score >= 50, maka pemain menang.
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t\t\t        " << strupr(pemain) << " MENANG";
			cout << "\n\n\t\t\t\t\t\t         Score : " << score;
			lagi(); 					// memanggil prosedur fungsi lagi.
			break;
		}
		else if(map[a][b]=="0"&&score<50){	//ketika koordinat pacman = 0, tetapi score < 50, maka pemain kalah.
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t\t\t  " << strupr(pemain) << " TIDAK SAMPAI TARGET";
			cout << "\n\n\t\t\t\t\t\t         Score : " << score;
			lagi(); 						// memanggil prosedur fungsi lagi.
			break;
		}
		
		system("cls");
		
		map[a][b]="@";						// menampilkan kembali karakter pacman setiap digerakkan.
		
		cout << pemain << " : " << score;	// menampilkan kembali score setiap pacman digerakkan.
		cout << "\n\n";
	
		for(x=0;x<17;x++){  				// menampilkan kembali map setiap pacman digerakkan.
			for(y=0;y<20;y++){
				cout << map [x][y] << " ";
			}
			cout << endl;
		}
	}
}

void map2(){
	
	system("cls");
	
	cout << "\n Instruksi : \n";
	cout << " 1. Gunakan tombol aswd untuk bergerak\n";
	cout << " 2. Makan titik (*) untuk mendapatkan poin\n";
	cout << " 3. Hindari pagar (#)\n";
	cout << " 4. Skor minimal 50 untuk menang\n";
	cout << "\n\n [ Klik Enter ]";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
	system("pause");
	system("cls");
	
	string map[17][20];		// array 2 dimensi untuk menyimpan koordinat map.
	int x,y;				// x menyimpan koordinat baris, y menyimpan koordinat kolom (pada array).
	int n=3, m=2;			// koordinat awal pacman.
	int score=0;			// mengembalikan nilai score secara default.
	char move;				// deklarasi variabel move.

// BENTUK MAP 2

	// menyimpan koordinat dinding dan rintangan pada map.
	for(x=0; x<17; x++){
		for(y=0; y<20; y++){
			if(x==0 || x==16){
				map[x][y]="#";
			}
			else if(y==0 || y==19){
				map[x][y]="#";
			}
			else if(y==2 && x==11){
				map[x][y]="#";
			}
			else if(y==4 && x==10){
				map[x][y]="#";
			}
			else if(y==11 && x==15){
				map[x][y]="#";
			}
			else if(x==5 && y>2 && y<10){
				map[x][y]="#";
			}
			else if(x==2 && y>1 && y<8){
				map[x][y]="#";
			}
			else if(x==9 && y>2 && y<10){
				map[x][y]="#";
			}
			else if(x==12 && y>2 && y<10){
				map[x][y]="#";
			}
			else if(x==14 && y>1 && y<10){
				map[x][y]="#";
			}
			else if(x==13 && y>11 && y<14){
				map[x][y]="#";
			}
			else if(y==9 && x>2 && x<10){
				map[x][y]="#";
			}
			else if(y==11 && x>5 && x<10){
				map[x][y]="#";
			}
			else if(y==12 && x>2 && x<10){
				map[x][y]="#";
			}
			else if(y==1 && x>6 && x<10){
				map[x][y]="#";
			}
			else if(y==14 && x>6 && x<19){
				map[x][y]="#";
			}
			else if(y==16 && x>1 && x<10){
				map[x][y]="#";
			}
			else{
				map[15][12]="0";	// koordinat finish.
				map[x][y]="*";		// koordinat bintang/makanan.
			}
		}
	}
	
// PACMAN DAN SKOR
	
	// koordinat pacman.
	map[n][m]="@";	
	
	// menampilkan nama pemain dan score yang diperoleh.
	cout << pemain << " : " << score;	
	cout << "\n\n";		
	
	// menampilkan map
	for(x=0; x<17; x++){
		for(y=0; y<20; y++){
			cout<<map[x][y]<<" ";
		}
		cout<<endl;
	}
	
	while(true){
		cout<<"\n(a,s,w,d) : ";
		/* tombol yang digunakan untuk menggerakkan pacman
			   a = kiri
			   d = kanan
			   w = atas
			   s = bawah
			*/
		move = getche();	// tombol yang ditekan akan langsung ditampilkan dan dijalankan tanpa harus mengklik enter.
		
		if(move=='s'){
			n++;					// koordinat baris akan bertambah.
			if(n>0){				// ketika n>0 (dinding), maka karakter titik(.)
				map[n-1][m]=" ";	// pada posisi awal akan dirubah menjadi kosong( ).
			}
		}
		else if(move=='w'){
			n--;					// koordinat baris akan berkurang.
			if(n>0){				// ketika n>0 (dinding), maka karakter titik(.)
				map[n+1][m]=" ";	// pada posisi awal akan dirubah menjadi kosong( ).
			}
		}
		else if(move=='a'){
			m--;					// koordinat kolom akan berkurang.
			if(m>0){				// ketika m>0 (dinding), maka karakter titik(.)
				map[n][m+1]=" ";	// pada posisi awal akan dirubah menjadi kosong( ).
				}
		}
		else if(move=='d'){
			m++;					// koordinat kolom akan bertambah.
			if(m>0){				// ketika n>0 (dinding), maka karakter titik(.)
				map[n][m-1]=" ";	// pada posisi awal akan dirubah menjadi kosong( ).
				}
		}
	
		if(map[n][m]=="0" && score>=50){	//ketika koordinat pacman = 0, dan score >= 50, maka pemain menang.
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t\t\t       " << strupr(pemain) << " MENANG";
			cout << "\n\n\t\t\t\t\t\t        Score : " << score;
			lagi(); 	// memanggil prosedur fungsi lagi.
			break;
		}
		else if(map[n][m]=="0" &&score<50){		//ketika koordinat pacman = 0, tetapi score < 50, maka pemain kalah.
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t\t\t  " << strupr(pemain) << " TIDAK SAMPAI TARGET";
			cout << "\n\n\t\t\t\t\t\t        Score : " << score;
			lagi(); 	// memanggil prosedur fungsi lagi.
			break;
		}
		
		if(map[n][m]=="#"){		// ketika koordinat pacman = pagar/rintangan, maka pemain kalah.
			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t\t\t         " << strupr(pemain) << " KALAH"; // strupt = mengkapitalkan nama pemain.
			cout << "\n\n\t\t\t\t\t\t         Score : " << score;
			lagi(); 	// memanggil prosedur fungsi lagi.
			break;
		}
		
		// ketika koordinat pacman = bintang(*), maka score bertambah 1.
		if(map[n][m]=="*"){
			score+=1;
		}
		
		system("cls");
		
		// menampilkan kembali karakter pacman setiap digerakkan.
		map[n][m]="@";
		
		// menampilkan kembali score setiap pacman digerakkan.
		cout << pemain << " : " << score;
		cout << endl << endl;
		
		// menampilkan kembali map setiap pacman digerakkan.
		for(x=0; x<17; x++){
			for(y=0; y<20; y++){
				cout<<map[x][y]<<" ";
			}
			cout<<endl;
		}
	}
}

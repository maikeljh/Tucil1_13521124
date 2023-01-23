# Tucil 1 Strategi Algoritma - The 24 Game
by : Michael Jonathan Halim - 13521124

## Daftar Isi
- [Deskripsi Singkat Permainan](#deskripsi-singkat-permainan)
- [Sistematika File](#sistematika-file)
- [Requirement dan Instalasi Program](#requirement-dan-instalasi-program)
- [Instruksi Pemakaian Program](#instruksi-pemakaian-program)
- [Tampilan Permainan](#tampilan-permainan)

## Deskripsi Singkat Permainan
Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). 

Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

## Sistematika File
```
Tucil1_13521124
├─── doc
|   └─── Tucil1_K2_13521124_Michael Jonathan Halim.pdf
├─── src
│   └─── Tucil1_13521124.cpp
├─── bin
│   └─── Tucil1_13521124.exe
├─── test
│   ├─── testcase_1.txt
│   ├─── testcase_2.txt
│   ├─── testcase_3.txt
│   ├─── testcase_4.txt
│   ├─── testcase_5.txt
│   ├─── testcase_6.txt
│   ├─── testcase_7.txt
│   ├─── testcase_8.txt
│   ├─── testcase_9.txt
│   └─── testcase_10.txt
└─── README.md
```

## Requirement dan Instalasi Program
- Download and install c++ compiler based on your operating system
- Download and install C++ standard libraries
- Libraries that are used :
  1. Iostream
  2. String
  3. Vector
  4. Fstream
  5. Ctime
- Don't forget to include the library path for the compiler
- Clone or download the repository
  >
        git clone https://github.com/maikeljh/Tucil1_13521124.git
- Compile Tucil1_13521124.cpp inside src to bin
  >
        g++ ./src/Tucil1_13521124.cpp -o ./bin/Tucil1_13521124.exe
- Run the .exe file inside bin
  >
        ./bin/Tucil1_13521124.exe
- Enjoy the game!

## Instruksi Pemakaian Program
1. Jalankan program
2. Input sesuai menu yang diinginkan (1 untuk input manual, 2 untuk input otomatis, 3 untuk exit)

    ![Screenshot_2491](https://user-images.githubusercontent.com/87570374/214026611-d9ab60c3-01d4-4c36-9917-c3c5296140aa.png)

3. Jika input manual, silahkan input 4 kartu dengan format yang benar (sesuai contoh di atas)

    ![Screenshot_2492](https://user-images.githubusercontent.com/87570374/214026822-18819b62-bdb3-4c13-a5a8-f3be95c60640.png)

4. Jika ingin simpan solusi, ketik "y". Lalu, isikan nama file yang diinginkan (nama file harus baru)

    ![Screenshot_2493](https://user-images.githubusercontent.com/87570374/214027070-2cb0b319-1fb3-4cdb-b60b-4358c4d3ddaf.png)

5. Jika ingin lanjut permainan, ketik "y".

    ![Screenshot_2494](https://user-images.githubusercontent.com/87570374/214027290-a8d2798c-8569-4a71-a81d-213dd3cebac3.png)

## Tampilan Permainan
### Main Menu
![ezgif com-gif-maker](https://user-images.githubusercontent.com/87570374/214030485-f5133a05-0001-40c8-b4cf-ea7b2d290128.gif)

### Validation Input
![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/87570374/214030903-accfcd7d-aca9-4428-8356-08c03b960191.gif)

### User Input
![ezgif com-gif-maker (2)](https://user-images.githubusercontent.com/87570374/214030912-3375ff71-fc53-4d9a-ab8c-524b04505a43.gif)

### Play Again
![ezgif com-gif-maker (3)](https://user-images.githubusercontent.com/87570374/214030939-ee20f9dc-1f17-4e43-89b6-facc5692f73d.gif)

### Generate Input and Saving File
![ezgif com-gif-maker (4)](https://user-images.githubusercontent.com/87570374/214030949-39ef7765-934f-4ebf-8b7e-ba4ff2fe81f0.gif)

### Exit
![ezgif com-gif-maker (5)](https://user-images.githubusercontent.com/87570374/214030961-7eedbf8c-7f3e-4f4f-8909-44c08b92f59f.gif)


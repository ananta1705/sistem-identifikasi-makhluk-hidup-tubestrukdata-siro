# Sistem Identifikasi Makhluk Hidup (Dynamic Tree) 🌳

Sistem pakar sederhana berbasis CLI (Command Line Interface) yang ditulis dalam C++. Program ini bertujuan untuk mengidentifikasi jenis makhluk hidup (Hewan, Tumbuhan, Manusia) berdasarkan serangkaian pertanyaan diagnostik menggunakan struktur data **Tree**.

## 🚀 Fitur Utama

### 1. 👤 Mode User
* **Identifikasi:** Menjawab pertanyaan dengan pilihan (Ya, Mungkin, Tidak) untuk menentukan hasil.
* **Riwayat:** Pengguna dapat melihat riwayat tes yang pernah dilakukan sebelumnya.
* **Skoring:** Sistem menghitung probabilitas berdasarkan jawaban user.

### 2. 🛡️ Mode Admin
* **Manajemen Pertanyaan:** Admin dapat Menambah, Mengedit, dan Menghapus pertanyaan secara dinamis.
* **Rebuild Tree:** Struktur Tree akan dibangun ulang secara otomatis saat data pertanyaan berubah.
* **Data Responden:** Melihat log aktivitas seluruh user.
* **Keamanan:** Dilindungi password sederhana.

## 📂 Struktur File

* `main.cpp`: Program utama yang memuat menu navigasi.
* `tree.h`: Header file berisi deklarasi struct (Node, Question, UserLog) dan prototipe fungsi.
* `tree.cpp`: File implementasi logika program dan struktur data Tree.


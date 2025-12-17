#include "tree.h"

Node* rootHewan = NULL;
Node* rootTumbuhan = NULL;
Node* rootManusia = NULL;
vector<Node*> allNodes;
vector<UserLog> historyLogs;
int logCounter = 1;
int questionIdCounter = 1;

// Database Pertanyaan
vector<Question> hewanQuestions;
vector<Question> tumbuhanQuestions;
vector<Question> manusiaQuestions;

Node::Node(string val, bool leaf) { // Konstruktor Node
    data = val;
    isLeaf = leaf;
    allNodes.push_back(this);
}

void linkToNext(Node* current, Node* nextNode) { // Menghubungkan node saat ini ke node berikutnya untuk semua jawaban
    current->children.push_back(nextNode); // 0: Tidak
    current->children.push_back(nextNode); // 1: Mungkin
    current->children.push_back(nextNode); // 2: Ya
}

void initTrees() {
    // Inisialisasi Pertanyaan Default untuk HEWAN
    hewanQuestions.clear();
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini bertulang belakang (vertebrata)?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini menyusui anaknya (mamalia)?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini pemakan daging (karnivora)?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini memiliki cakar yang tajam dan dapat ditarik masuk?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini bisa mengaum dengan suara keras?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah tubuhnya memiliki pola loreng (belang) hitam?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini hidup menyendiri (soliter), bukan berkelompok?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah ukuran tubuhnya lebih kecil dibanding harimau jenis lain?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah pola lorengnya lebih rapat dan gelap dibanding harimau lain?", "Hewan"});
    hewanQuestions.push_back({questionIdCounter++, "Apakah hewan ini endemik (hanya hidup) di Pulau Sumatera?", "Hewan"});

    // Inisialisasi Pertanyaan Default untuk TUMBUHAN
    tumbuhanQuestions.clear();
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah tumbuhan ini memiliki batang berkayu (bukan herba)?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah tumbuhan ini berkembang biak dengan biji?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah bijinya tertutup oleh daging buah (angiospermae)?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah biji tumbuhan ini berkeping dua (dikotil)?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah tumbuhan ini mengeluarkan getah berwarna bening atau putih?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah buahnya memiliki biji tunggal yang besar (pelok)?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah daunnya berbentuk lanset memanjang dengan tepi rata?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah daging buahnya berwarna kuning-oranye dan manis saat matang?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah buahnya memiliki aroma yang sangat harum khas saat matang?", "Tumbuhan"});
    tumbuhanQuestions.push_back({questionIdCounter++, "Apakah nama ilmiah tumbuhan ini adalah Mangifera indica?", "Tumbuhan"});

    // Inisialisasi Pertanyaan Default untuk MANUSIA
    manusiaQuestions.clear();
    manusiaQuestions.push_back({questionIdCounter++, "Apakah organisme ini multiseluler dengan sistem organ kompleks?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah organisme ini termasuk mamalia (menyusui)?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah memiliki ibu jari yang dapat bergerak berlawanan (opposable thumb)?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah organisme ini tidak memiliki ekor?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah berjalan dengan dua kaki (bipedal) secara permanen?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah memiliki otak yang sangat besar relatif terhadap ukuran tubuh?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah mampu berkomunikasi dengan bahasa kompleks (tata bahasa)?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah mampu menciptakan teknologi dan peradaban?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah memiliki kesadaran diri dan kemampuan berpikir abstrak tinggi?", "Manusia"});
    manusiaQuestions.push_back({questionIdCounter++, "Apakah spesies organisme ini adalah Homo sapiens?", "Manusia"});

    rebuildTrees();
}

void rebuildTrees() {  
    // Hapus tree lama
    for (Node* node : allNodes) {
        delete node;
    }
    allNodes.clear();

    // ==========================================
    // REBUILD TREE HEWAN
    // ==========================================
    Node* h_end = new Node("SELESAI", true); 
    Node* currentH = h_end;
    
    for (int i = hewanQuestions.size() - 1; i >= 0; i--) {
        string questionText = to_string(i + 1) + "/" + to_string(hewanQuestions.size()) + ". " + hewanQuestions[i].text;
        Node* newNode = new Node(questionText, false);
        linkToNext(newNode, currentH);
        currentH = newNode;
    }
    rootHewan = currentH;

    // ==========================================
    // REBUILD TREE TUMBUHAN
    // ==========================================
    Node* t_end = new Node("SELESAI", true);
    Node* currentT = t_end;
    
    for (int i = tumbuhanQuestions.size() - 1; i >= 0; i--) {
        string questionText = to_string(i + 1) + "/" + to_string(tumbuhanQuestions.size()) + ". " + tumbuhanQuestions[i].text;
        Node* newNode = new Node(questionText, false);
        linkToNext(newNode, currentT);
        currentT = newNode;
    }
    rootTumbuhan = currentT;

    // ==========================================
    // REBUILD TREE MANUSIA
    // ==========================================
    Node* m_end = new Node("SELESAI", true);
    Node* currentM = m_end;
    
    for (int i = manusiaQuestions.size() - 1; i >= 0; i--) {
        string questionText = to_string(i + 1) + "/" + to_string(manusiaQuestions.size()) + ". " + manusiaQuestions[i].text;
        Node* newNode = new Node(questionText, false);
        linkToNext(newNode, currentM);
        currentM = newNode;
    }
    rootManusia = currentM;
}

void cleanUpMemory() {
    for (Node* node : allNodes) {
        delete node;
    }
    allNodes.clear();
}

void playGame(Node* current, UserLog &currentLog, int skorYa) {
    if (current->isLeaf) {
        cout << "\n=======================================\n";
        cout << "           HASIL ANALISIS            \n";
        cout << "=======================================\n";
        
        string kesimpulan;
        string target = currentLog.kategori;
        
        int totalQuestions = 0;
        if (target == "Hewan") totalQuestions = hewanQuestions.size();
        else if (target == "Tumbuhan") totalQuestions = tumbuhanQuestions.size();
        else totalQuestions = manusiaQuestions.size();
        
        if (skorYa >= totalQuestions * 0.8) {
            if (target == "Hewan") kesimpulan = "INI ADALAH HARIMAU SUMATERA!";
            else if (target == "Tumbuhan") kesimpulan = "INI ADALAH POHON MANGGA!";
            else kesimpulan = "INI ADALAH MANUSIA (HOMO SAPIENS)!";
        } else if (skorYa >= totalQuestions * 0.5) {
            kesimpulan = "Kemungkinan besar ini " + target + ", tapi ada ciri yang tidak cocok.";
        } else {
            kesimpulan = "Bukan " + target + " (Ciri-ciri tidak cocok).";
        }
        
        cout << "Kesimpulan: " << kesimpulan << endl;
        cout << "=======================================\n";
        currentLog.statusAkhir = kesimpulan;
        return;
    }

    cout << "\n" << current->data << endl;
    cout << "1. TIDAK\n";
    cout << "2. MUNGKIN\n";
    cout << "3. YA\n";
    cout << "Pilih: ";
    int choice;
    cin >> choice;

    int index = choice - 1;
    if (index >= 0 && index < 3) {
        string strAns;
        int tambahYa = 0;

        if (choice == 1) { 
            strAns = "TIDAK"; 
            tambahYa = 0; 
        } else if (choice == 2) { 
            strAns = "MUNGKIN"; 
            tambahYa = 0; 
        } else { 
            strAns = "YA"; 
            tambahYa = 1; 
        }

        currentLog.jejak.push_back(current->data + " -> " + strAns);
        
        playGame(current->children[index], currentLog, skorYa + tambahYa);
    } else {
        cout << "Pilihan tidak valid! Silakan pilih 1, 2, atau 3.\n";
        playGame(current, currentLog, skorYa);
    }
}

void viewMyHistory(string playerName) {
    bool found = false;
    cout << "\n========================================\n";
    cout << "   RIWAYAT PERMAINAN: " << playerName << "\n";
    cout << "========================================\n";
    
    for (const auto& log : historyLogs) {
        if (log.namaPlayer == playerName) {
            found = true;
            cout << "\nID: " << log.id << " | Kategori: " << log.kategori << endl;
            cout << "Hasil: " << log.statusAkhir << endl;
            cout << "\nDetail Jawaban:\n";
            for(const string& s : log.jejak) {
                cout << "   " << s << endl;
            }
            cout << "----------------------------------------\n";
        }
    }
    
    if (!found) {
        cout << "Belum ada riwayat permainan untuk user ini.\n";
    }
    cout << "========================================\n";
}

// ==========================================
// FUNGSI ADMIN - KELOLA PERTANYAAN
// ==========================================

void lihatSemuaPertanyaan() {
    cout << "\n========================================\n";
    cout << "       SEMUA PERTANYAAN SISTEM         \n";
    cout << "========================================\n";
    
    cout << "\n--- KATEGORI HEWAN ---\n";
    for (size_t i = 0; i < hewanQuestions.size(); i++) {
        cout << (i+1) << ". " << hewanQuestions[i].text << endl;
    }
    
    cout << "\n--- KATEGORI TUMBUHAN ---\n";
    for (size_t i = 0; i < tumbuhanQuestions.size(); i++) {
        cout << (i+1) << ". " << tumbuhanQuestions[i].text << endl;
    }
    
    cout << "\n--- KATEGORI MANUSIA ---\n";
    for (size_t i = 0; i < manusiaQuestions.size(); i++) {
        cout << (i+1) << ". " << manusiaQuestions[i].text << endl;
    }
    cout << "========================================\n";
}

void lihatPertanyaanKategori(string kategori) {
    vector<Question>* questions = NULL;
    
    if (kategori == "Hewan") questions = &hewanQuestions;
    else if (kategori == "Tumbuhan") questions = &tumbuhanQuestions;
    else if (kategori == "Manusia") questions = &manusiaQuestions;
    
    if (questions == NULL) {
        cout << "Kategori tidak valid!\n";
        return;
    }
    
    cout << "\n========================================\n";
    cout << "   PERTANYAAN KATEGORI: " << kategori << "\n";
    cout << "========================================\n";
    
    for (size_t i = 0; i < questions->size(); i++) {
        cout << (i+1) << ". " << (*questions)[i].text << endl;
    }
    cout << "========================================\n";
}

void tambahPertanyaan() {
    cout << "\n========================================\n";
    cout << "         TAMBAH PERTANYAAN BARU        \n";
    cout << "========================================\n";
    
    cout << "Pilih Kategori:\n";
    cout << "1. Hewan\n";
    cout << "2. Tumbuhan\n";
    cout << "3. Manusia\n";
    cout << "Pilih: ";
    int kat;
    cin >> kat;
    cin.ignore();
    
    string kategori;
    vector<Question>* questions = NULL;
    
    if (kat == 1) { kategori = "Hewan"; questions = &hewanQuestions; }
    else if (kat == 2) { kategori = "Tumbuhan"; questions = &tumbuhanQuestions; }
    else if (kat == 3) { kategori = "Manusia"; questions = &manusiaQuestions; }
    else {
        cout << "Kategori tidak valid!\n";
        return;
    }
    
    cout << "\nMasukkan pertanyaan baru: ";
    string newQuestion;
    getline(cin, newQuestion);
    
    if (newQuestion.empty()) {
        cout << "Pertanyaan tidak boleh kosong!\n";
        return;
    }
    
    Question q;
    q.id = questionIdCounter++;
    q.text = newQuestion;
    q.kategori = kategori;
    
    questions->push_back(q);
    
    cout << "\nPertanyaan berhasil ditambahkan!\n";
    cout << "Rebuilding tree...\n";
    rebuildTrees();
    cout << "Tree berhasil diperbarui!\n";
}

void editPertanyaan() {
    cout << "\n========================================\n";
    cout << "           EDIT PERTANYAAN             \n";
    cout << "========================================\n";
    
    cout << "Pilih Kategori:\n";
    cout << "1. Hewan\n";
    cout << "2. Tumbuhan\n";
    cout << "3. Manusia\n";
    cout << "Pilih: ";
    int kat;
    cin >> kat;
    cin.ignore();
    
    string kategori;
    vector<Question>* questions = NULL;
    
    if (kat == 1) { kategori = "Hewan"; questions = &hewanQuestions; }
    else if (kat == 2) { kategori = "Tumbuhan"; questions = &tumbuhanQuestions; }
    else if (kat == 3) { kategori = "Manusia"; questions = &manusiaQuestions; }
    else {
        cout << "Kategori tidak valid!\n";
        return;
    }
    
    lihatPertanyaanKategori(kategori);
    
    cout << "\nMasukkan nomor pertanyaan yang ingin diedit: ";
    int nomor;
    cin >> nomor;
    cin.ignore();
    
    if (nomor < 1 || nomor > (int)questions->size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    
    cout << "Pertanyaan lama: " << (*questions)[nomor-1].text << endl;
    cout << "Masukkan pertanyaan baru: ";
    string newText;
    getline(cin, newText);
    
    if (newText.empty()) {
        cout << "Pertanyaan tidak boleh kosong!\n";
        return;
    }
    
    (*questions)[nomor-1].text = newText;
    
    cout << "\nPertanyaan berhasil diubah!\n";
    cout << "Rebuilding tree...\n";
    rebuildTrees();
    cout << "Tree berhasil diperbarui!\n";
}

void hapusPertanyaan() {
    cout << "\n========================================\n";
    cout << "           HAPUS PERTANYAAN            \n";
    cout << "========================================\n";
    
    cout << "Pilih Kategori:\n";
    cout << "1. Hewan\n";
    cout << "2. Tumbuhan\n";
    cout << "3. Manusia\n";
    cout << "Pilih: ";
    int kat;
    cin >> kat;
    
    string kategori;
    vector<Question>* questions = NULL;
    
    if (kat == 1) { kategori = "Hewan"; questions = &hewanQuestions; }
    else if (kat == 2) { kategori = "Tumbuhan"; questions = &tumbuhanQuestions; }
    else if (kat == 3) { kategori = "Manusia"; questions = &manusiaQuestions; }
    else {
        cout << "Kategori tidak valid!\n";
        return;
    }
    
    lihatPertanyaanKategori(kategori);
    
    cout << "\nMasukkan nomor pertanyaan yang ingin dihapus: ";
    int nomor;
    cin >> nomor;
    
    if (nomor < 1 || nomor > (int)questions->size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    
    if (questions->size() <= 1) {
        cout << "Tidak dapat menghapus! Minimal harus ada 1 pertanyaan.\n";
        return;
    }
    
    cout << "Yakin ingin menghapus: " << (*questions)[nomor-1].text << " ?\n";
    cout << "1. Ya\n2. Tidak\nPilih: ";
    int konfirmasi;
    cin >> konfirmasi;
    
    if (konfirmasi == 1) {
        questions->erase(questions->begin() + (nomor - 1));
        cout << "\nPertanyaan berhasil dihapus!\n";
        cout << "Rebuilding tree...\n";
        rebuildTrees();
        cout << "Tree berhasil diperbarui!\n";
    } else {
        cout << "Penghapusan dibatalkan.\n";
    }
}

void adminKelolaPertanyaan() {
    while (true) {
        cout << "\n========================================\n";
        cout << "       KELOLA PERTANYAAN (ADMIN)       \n";
        cout << "========================================\n";
        cout << "1. Lihat Semua Pertanyaan\n";
        cout << "2. Tambah Pertanyaan\n";
        cout << "3. Edit Pertanyaan\n";
        cout << "4. Hapus Pertanyaan\n";
        cout << "5. Kembali\n";
        cout << "========================================\n";
        cout << "Pilih: ";
        
        int pilihan;
        cin >> pilihan;
        
        if (pilihan == 1) {
            lihatSemuaPertanyaan();
        } else if (pilihan == 2) {
            tambahPertanyaan();
        } else if (pilihan == 3) {
            editPertanyaan();
        } else if (pilihan == 4) {
            hapusPertanyaan();
        } else if (pilihan == 5) {
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

void adminKelolaData() {
    cout << "\n========================================\n";
    cout << "         DATA SEMUA RESPONDEN          \n";
    cout << "========================================\n";
    
    if (historyLogs.empty()) {
        cout << "Belum ada data responden.\n";
    } else {
        for(const auto& l : historyLogs) {
            cout << "\nUser: " << l.namaPlayer << endl;
            cout << "Kategori: " << l.kategori << endl;
            cout << "Status: " << l.statusAkhir << endl;
            cout << "Detail:\n";
            for(const string& s : l.jejak) {
                cout << "   " << s << endl;
            }
            cout << "----------------------------------------\n";
        }
    }
    cout << "========================================\n";
}

void userMenu() {
    string nama;
    cout << "\nNama User: "; 
    cin.ignore(); 
    getline(cin, nama);
    
    cout << "\nPilih Target Analisis:\n";
    cout << "1. Hewan\n";
    cout << "2. Tumbuhan\n";
    cout << "3. Manusia\n";
    cout << "4. Lihat Riwayat Saya\n";
    cout << "5. Kembali\n";
    cout << "Pilih: ";
    
    int kat; 
    cin >> kat;
    
    if (kat == 4) {
        viewMyHistory(nama);
        return;
    }
    
    if (kat == 5) {
        return;
    }
    
    Node* startNode = NULL;
    string catName = "";

    if (kat == 1) { 
        startNode = rootHewan; 
        catName = "Hewan"; 
    } else if (kat == 2) { 
        startNode = rootTumbuhan; 
        catName = "Tumbuhan"; 
    } else if (kat == 3) { 
        startNode = rootManusia; 
        catName = "Manusia"; 
    } else { 
        cout << "Pilihan tidak valid.\n"; 
        return; 
    }

    UserLog log;
    log.id = logCounter++;
    log.namaPlayer = nama;
    log.kategori = catName;

    cout << "\nMemulai analisis " << catName << "...\n";
    cout << "Jawab pertanyaan berikut!\n";

    playGame(startNode, log, 0);
    historyLogs.push_back(log);
    
    cout << "\nHasil telah disimpan ke riwayat Anda!\n";
}

void adminMenu() {
    string pass;
    cout << "\nPassword Admin: "; 
    cin >> pass;
    
    if (pass != "admin123") {
        cout << "Password salah!\n";
        return;
    }

    while (true) {
        cout << "\n========================================\n";
        cout << "           MENU ADMIN                  \n";
        cout << "========================================\n";
        cout << "1. Kelola Pertanyaan\n";
        cout << "2. Lihat Data Responden\n";
        cout << "3. Logout\n";
        cout << "========================================\n";
        cout << "Pilih: ";
        
        int pilihan;
        cin >> pilihan;
        
        if (pilihan == 1) {
            adminKelolaPertanyaan();
        } else if (pilihan == 2) {
            adminKelolaData();
        } else if (pilihan == 3) {
            cout << "Logout berhasil.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}
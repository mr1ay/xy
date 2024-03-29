#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char* argv[]) {
    // Komut satırı argümanlarını kontrol etme
    if (argc < 3) {
        std::cerr << "Usage xy <width> <height> " << std::endl;
        std::cerr << "Usage xy <width> <height> [x_coord] [y_coord]" << std::endl;
        return 1; // Hata durumunda programdan çıkış
    }

    // Genişlik ve yükseklik değerlerini argümanlardan al
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);

    // Varsayılan konum
    int x = 0;
    int y = 0;

    // Eğer 3. ve 4. argümanlar verilmişse, bunları al
    if (argc >= 4) {
        x = std::stoi(argv[3]);
    }
    if (argc >= 5) {
    system("mode 20,1");
        y = std::stoi(argv[4]);
    }

    // Mode komutunu oluştur
    std::string modeCommand = "mode ";
    modeCommand += std::to_string(width) + "," + std::to_string(height);

    // Pencere boyutunu ayarla
    system(modeCommand.c_str());

    // Pencere konumunu ayarla
    HWND consoleWindow = GetConsoleWindow(); // Konsol penceresinin HWND'sini alır
    SetWindowPos(consoleWindow, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER); // Pencereyi belirtilen koordinatlara taşır

    // Kullanıcıya bir tuşa basması için beklemeyi sağla
  

    return 0;
}

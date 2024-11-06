#include <iostream>
#include <cmath>

int main() {
    // Переменные для хранения размера файла и скорости соединения
    float fileSize;      // Размер файла в мегабайтах
    float connectionSpeed; // Скорость соединения в мегабайтах в секунду

    // Запрос размера файла у пользователя
    std::cout << "Укажите размер файла для скачивания: ";
    std::cin >> fileSize;

    // Проверка корректности ввода размера файла
    if (fileSize <= 0) {
        std::cout << "Размер файла должен быть положительным числом." << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    // Запрос скорости соединения у пользователя
    std::cout << "Какова скорость вашего соединения? ";
    std::cin >> connectionSpeed;

    // Проверка корректности ввода скорости соединения
    if (connectionSpeed <= 0) {
        std::cout << "Скорость соединения должна быть положительным числом." << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    // Переменные для отслеживания прогресса загрузки
    float downloaded = 0; // Скачано данных в мегабайтах
    int seconds = 0;      // Счетчик времени в секундах

    // Цикл, который выполняется до тех пор, пока файл не будет загружен полностью
    while (downloaded < fileSize) {
        // Увеличиваем скачанное количество на скорость соединения
        downloaded += connectionSpeed;

        // Увеличиваем счетчик времени
        seconds++;

        // Ограничиваем скачанное количество до размера файла
        if (downloaded > fileSize) {
            downloaded = fileSize;
        }

        // Вычисляем процент загруженного файла
        int percentage = static_cast<int>(std::floor((downloaded / fileSize) * 100));

        // Выводим информацию о прогрессе загрузки
        std::cout << "Прошло " << seconds << " сек. "
                  << "Скачано " << static_cast<int>(downloaded) 
                  << " из " << static_cast<int>(fileSize) 
                  << " МБ (" << percentage << "%)." << std::endl;

        // Задержка на 1 секунду для имитации времени загрузки (необязательно)
        // В реальной программе можно использовать sleep(1), но это требует дополнительной библиотеки.
        // Здесь мы просто используем цикл, чтобы показать прогресс.
    }

    // Выводим итоговое время загрузки
    std::cout << "Загрузка завершена за " << seconds << " секунд." << std::endl;

    return 0; 
}
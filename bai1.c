#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Hàm chuẩn hóa một xâu họ tên
void chuanHoa(char* str) {
    int n = strlen(str);
    char result[81] = "";  // Xâu kết quả chuẩn hóa
    int idx = 0;           // Vị trí trong xâu kết quả
    int capitalize = 1;    // Biến để viết hoa chữ cái đầu

    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            // Viết hoa chữ cái đầu từ
            if (capitalize) {
                result[idx++] = toupper(str[i]);
                capitalize = 0;
            } else {
                // Các ký tự khác viết thường
                result[idx++] = tolower(str[i]);
            }
        } else {
            // Nếu gặp dấu cách
            if (idx > 0 && result[idx - 1] != ' ') {
                result[idx++] = ' ';  // Chỉ thêm dấu cách khi cần
            }
            capitalize = 1;  // Sẵn sàng viết hoa từ mới
        }
    }

    // Loại bỏ dấu cách thừa ở cuối xâu
    if (idx > 0 && result[idx - 1] == ' ') {
        result[idx - 1] = '\0';
    } else {
        result[idx] = '\0';
    }

    // Ghi kết quả lại vào xâu ban đầu
    strcpy(str, result);
}

int main() {
    int T;
    char name[81];  // Xâu họ tên tối đa 80 ký tự

    // Nhập số bộ test
    printf("Nhập số bộ test: ");
    scanf("%d", &T);
    getchar();  // Đọc ký tự newline sau số test

    for (int t = 0; t < T; t++) {
        // Nhập xâu họ tên
        printf("Nhập họ tên: ");
        fgets(name, sizeof(name), stdin);

        // Loại bỏ ký tự xuống dòng ở cuối xâu (nếu có)
        name[strcspn(name, "\n")] = '\0';

        // Chuẩn hóa xâu họ tên
        chuanHoa(name);

        // In xâu đã chuẩn hóa
        printf("Họ tên chuẩn hóa: %s\n", name);
    }

    return 0;
}

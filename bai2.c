#include <stdio.h>
#include <string.h>

// Cấu trúc để lưu thông tin thí sinh
typedef struct {
    int maThiSinh;     // Mã thí sinh
    char ten[101];     // Tên thí sinh
    char ngaySinh[11]; // Ngày sinh
    float diem1, diem2, diem3; // Điểm 3 môn thi
    float tongDiem;    // Tổng điểm
} ThiSinh;

// Hàm nhập một dòng chuỗi
void nhapChuoi(char s[], int maxLen) {
    fgets(s, maxLen, stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
}

// Hàm hoán đổi hai thí sinh (dùng cho sắp xếp)
void swap(ThiSinh* a, ThiSinh* b) {
    ThiSinh temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp thí sinh theo mã số tăng dần
void sapXepTheoMaHocSinh(ThiSinh ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].maThiSinh > ds[j + 1].maThiSinh) {
                swap(&ds[j], &ds[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Nhập số thí sinh: ");
    scanf("%d", &n);
    getchar(); // Loại bỏ ký tự xuống dòng sau khi nhập số

    ThiSinh ds[100]; // Mảng lưu danh sách thí sinh

    // Nhập thông tin thí sinh
    for (int i = 0; i < n; i++) {
        ds[i].maThiSinh = i + 1; // Mã thí sinh tự động tăng
        printf("Nhập tên thí sinh %d: ", i + 1);
        nhapChuoi(ds[i].ten, sizeof(ds[i].ten));

        printf("Nhập ngày sinh thí sinh %d: ", i + 1);
        nhapChuoi(ds[i].ngaySinh, sizeof(ds[i].ngaySinh));

        printf("Nhập điểm môn 1, môn 2, môn 3 của thí sinh %d: ", i + 1);
        scanf("%f %f %f", &ds[i].diem1, &ds[i].diem2, &ds[i].diem3);
        getchar(); // Loại bỏ ký tự xuống dòng sau khi nhập điểm

        ds[i].tongDiem = ds[i].diem1 + ds[i].diem2 + ds[i].diem3; // Tính tổng điểm
    }

    // Tìm tổng điểm cao nhất
    float maxDiem = ds[0].tongDiem;
    for (int i = 1; i < n; i++) {
        if (ds[i].tongDiem > maxDiem) {
            maxDiem = ds[i].tongDiem;
        }
    }

    // Sắp xếp danh sách theo mã thí sinh tăng dần
    sapXepTheoMaHocSinh(ds, n);
    // Check
    // for ( int h= 0; h<3;h++){
    //     printf("%s \n",ds[h].ten);
    // }    
    // In ra các thí sinh có tổng điểm bằng maxDiem
    printf("Thủ khoa: \n");
    for (int i = 0; i < n; i++) {
        if (ds[i].tongDiem == maxDiem) {
            printf("%d %s %s %.1f\n", ds[i].maThiSinh, ds[i].ten, ds[i].ngaySinh, ds[i].tongDiem);
        }
    }

    return 0;
}

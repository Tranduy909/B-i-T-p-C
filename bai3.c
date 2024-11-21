#include <stdio.h>

void tinhTichMaTran(int n, int m, int A[][100]) {
    int At[100][100];    // Ma trận chuyển vị của A
    int C[100][100];     // Ma trận tích

    // Tạo ma trận chuyển vị At
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            At[j][i] = A[i][j];
        }
    }

    // Tính ma trận tích C = A * At
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * At[k][j];
            }
        }
    }

    // In kết quả
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T;
    printf("Nhập số bộ test: ");
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n, m;
        printf("Nhập số hàng và số cột của ma trận (n m): ");
        scanf("%d %d", &n, &m);

        int A[100][100];

        // Nhập ma trận A
        printf("Nhập ma trận A:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        // In thứ tự bộ test
        printf("Test %d:\n", t);

        // Gọi hàm tính tích ma trận
        tinhTichMaTran(n, m, A);
    }

    return 0;
}

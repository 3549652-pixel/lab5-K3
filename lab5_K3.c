#include <stdio.h>
#include <math.h>

int main() {
    // Laboratorna robota 5. K = 3.
    // Zavdannia: 11, 18, 37, 74, 135, 16, 143, 102, 109, 170.

    // Zavdannia 11
    {
        int i, j, count, prime;

        printf("\nZavdannia 11a. Chysla bilshi 300, kratni 13 abo 17:\n");
        count = 0;
        i = 301;
        while (count < 20) {
            if (i % 13 == 0 || i % 17 == 0) {
                printf("%d ", i);
                count++;
            }
            i++;
        }
        printf("\n");

        printf("Zavdannia 11b. Pershi 30 prostykh chysel:\n");
        count = 0;
        i = 2;
        while (count < 30) {
            prime = 1;
            for (j = 2; j < i; j++) {
                if (i % j == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime == 1) {
                printf("%d ", i);
                count++;
            }
            i++;
        }
        printf("\n");
    }

    // Zavdannia 18
    {
        double a[100], sum = 0;
        int n, i, sign = 1;

        printf("\nZavdannia 18. Kilkist elementiv (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) return 1;
        for (i = 0; i < n; i++) {
            printf("a[%d] = ", i + 1);
            scanf("%lf", &a[i]);
        }
        for (i = 0; i < n; i++) {
            sum += sign * a[i];
            sign = -sign;
        }
        printf("Suma = %.2f\n", sum);
    }

    // Zavdannia 37
    {
        int a[100], n, m, l, i, count = 0;

        printf("\nZavdannia 37. Kilkist chysel (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) return 1;
        printf("Vvedit M ta L (M > 0, 0 <= L < M): ");
        scanf("%d %d", &m, &l);
        if (m <= 0 || l < 0 || l >= m) return 1;
        for (i = 0; i < n; i++) {
            printf("a[%d] = ", i + 1);
            scanf("%d", &a[i]);
        }
        printf("Chysla, dlia yakykh a %% M = L: ");
        for (i = 0; i < n; i++) {
            if (a[i] % m == l) {
                printf("%d ", a[i]);
                count++;
            }
        }
        if (count == 0) printf("Nemaye takykh chysel");
        printf("\n");
    }

    // Zavdannia 74
    {
        double a[15];
        int i, pos = 0;

        printf("\nZavdannia 74. Vvedit 15 chysel:\n");
        for (i = 0; i < 15; i++) {
            printf("a[%d] = ", i + 1);
            scanf("%lf", &a[i]);
        }
        for (i = 0; i < 15; i++) {
            if (a[i] < 0 && pos == 0) pos = i + 1;
        }
        if (pos == 0)
            printf("Vid'yemnykh chysel nemaye\n");
        else
            printf("Pershe vid'yemne chyslo na mistsi %d\n", pos);
    }

    // Zavdannia 135
    {
        int weather[30], i;
        double height;

        printf("\nZavdannia 135. Pochatkova vysota ravlyka (sm, 0-500): ");
        scanf("%lf", &height);
        if (height < 0 || height > 500) return 1;
        printf("Dlia kozhnogo dnya: 1 - soniachnyi, 0 - khmarnyi.\n");
        for (i = 0; i < 30; i++) {
            printf("Den %d: ", i + 1);
            scanf("%d", &weather[i]);
            if (weather[i] != 0 && weather[i] != 1) return 1;
        }
        for (i = 0; i < 30; i++) {
            if (weather[i] == 1)
                height += 2;
            else
                height -= 1;
        }
        printf("Vysota pislia 30 dniv = %.2f sm\n", height);
    }

    // Zavdannia 16
    {
        double a[100], x, b;
        int n, i;

        printf("\nZavdannia 16. Kilkist elementiv (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) return 1;
        for (i = 0; i < n; i++) {
            printf("a[%d] = ", i + 1);
            scanf("%lf", &a[i]);
        }
        printf("Vvedit chysla a ta b: ");
        scanf("%lf %lf", &x, &b);

        printf("a) Zbilshyty vdvichi: ");
        for (i = 0; i < n; i++) printf("%.2f ", a[i] * 2);
        printf("\n");

        printf("b) Zmenshyty na a: ");
        for (i = 0; i < n; i++) printf("%.2f ", a[i] - x);
        printf("\n");

        printf("c) Podilyty na pershyi element: ");
        if (a[0] == 0) {
            printf("Ne mozhna dilyty na nul\n");
        } else {
            for (i = 0; i < n; i++) printf("%.2f ", a[i] / a[0]);
            printf("\n");
        }

        printf("d) Zmenshyty na 20: ");
        for (i = 0; i < n; i++) printf("%.2f ", a[i] - 20);
        printf("\n");

        printf("e) Pomnozhyty na ostannii element: ");
        for (i = 0; i < n; i++) printf("%.2f ", a[i] * a[n - 1]);
        printf("\n");

        printf("f) Zbilshyty na b: ");
        for (i = 0; i < n; i++) printf("%.2f ", a[i] + b);
        printf("\n");
    }

    // Zavdannia 143
    {
        double x[30], y[30], dist, maxDist = -1;
        int n, i, j, first = 0, second = 0;

        printf("\nZavdannia 143. Kilkist tochok (2-30): ");
        scanf("%d", &n);
        if (n < 2 || n > 30) return 1;
        for (i = 0; i < n; i++) {
            printf("Tochka %d (x y): ", i + 1);
            scanf("%lf %lf", &x[i], &y[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                dist = (x[i] - x[j]) * (x[i] - x[j])
                     + (y[i] - y[j]) * (y[i] - y[j]);
                if (dist > maxDist) {
                    maxDist = dist;
                    first = i + 1;
                    second = j + 1;
                }
            }
        }
        printf("Nayviddalenishi tochky: %d i %d\n", first, second);
        printf("Vidstan = %.2f\n", sqrt(maxDist));
    }

    // Zavdannia 102
    {
        int a[100], n, i, pos = -1;

        printf("\nZavdannia 102. Kilkist elementiv (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) return 1;
        for (i = 0; i < n; i++) {
            printf("a[%d] = ", i + 1);
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) {
            if (a[i] % 6 != 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            printf("Elementy dlia vydalennia ne znaydeni\n");
        } else {
            for (i = pos; i < n - 1; i++) a[i] = a[i + 1];
            a[n - 1] = 0;
            printf("Masiv pislia vydalennia: ");
            for (i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
        }
    }

    // Zavdannia 109
    {
        double a[101], max;
        int n, k, i;

        printf("\nZavdannia 109. Kilkist elementiv (1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) return 1;
        for (i = 0; i < n; i++) {
            printf("a[%d] = ", i + 1);
            scanf("%lf", &a[i]);
        }
        printf("Vvedit nomer mistsia k (1-%d): ", n + 1);
        scanf("%d", &k);
        if (k < 1 || k > n + 1) return 1;

        max = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
        }
        for (i = n; i >= k; i--) a[i] = a[i - 1];
        a[k - 1] = max;

        printf("Masiv pislia vstavky: ");
        for (i = 0; i < n + 1; i++) printf("%.2f ", a[i]);
        printf("\n");
    }

    // Zavdannia 170
    {
        double v[50], v0, a;
        int i;

        printf("\nZavdannia 170. Pochatkova shvydkist V0 ta pryskorennia a: ");
        scanf("%lf %lf", &v0, &a);
        for (i = 0; i < 50; i++) v[i] = v0 + a * (i + 1);
        for (i = 0; i < 50; i++) {
            printf("t = %d s, V = %.2f\n", i + 1, v[i]);
        }
    }

    return 0;
}

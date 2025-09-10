#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool common(int **languages, int *languagesColSize, int u, int v) {
    for (int i = 0; i < languagesColSize[u]; i++) {
        for (int j = 0; j < languagesColSize[v]; j++) {
            if (languages[u][i] == languages[v][j]) {
                return true;
            }
        }
    }
    return false;
}

int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize,
                     int** friendships, int friendshipsSize, int* friendshipsColSize) {
    int *need = (int*)calloc(languagesSize + 1, sizeof(int));  
    int needCount = 0;

    for (int i = 0; i < friendshipsSize; i++) {
        int u = friendships[i][0];
        int v = friendships[i][1];
        if (!common(languages, languagesColSize, u - 1, v - 1)) {
            if (!need[u]) { need[u] = 1; needCount++; }
            if (!need[v]) { need[v] = 1; needCount++; }
        }
    }
    if (needCount == 0) {
        free(need);
        return 0;
    }

    int *mpp = (int*)calloc(n + 1, sizeof(int));
    int maxi = 0;
    for (int person = 1; person <= languagesSize; person++) {
        if (need[person]) {
            int idx = person - 1;
            for (int j = 0; j < languagesColSize[idx]; j++) {
                int lang = languages[idx][j];
                mpp[lang]++;
                if (mpp[lang] > maxi) maxi = mpp[lang];
            }
        }
    }

    free(need);
    free(mpp);
    return needCount - maxi;
}
int main() {
    int n = 3;

    // languages = [[2], [1,3], [1,2]]
    int l1[] = {2}, l2[] = {1, 3}, l3[] = {1, 2};
    int* languages[] = {l1, l2, l3};
    int languagesColSize[] = {1, 2, 2};
    int languagesSize = 3;

    // friendships = [[1,2], [1,3], [2,3]]
    int f1[] = {1, 2}, f2[] = {1, 3}, f3[] = {2, 3};
    int* friendships[] = {f1, f2, f3};
    int friendshipsColSize[] = {2, 2, 2};
    int friendshipsSize = 3;

    int result = minimumTeachings(n, languages, languagesSize, languagesColSize,
                                  friendships, friendshipsSize, friendshipsColSize);

    printf("Minimum Teachings: %d\n", result);
    return 0;
}

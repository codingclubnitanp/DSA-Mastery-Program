#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int** vec;
    int rows;
} Spreadsheet;

int decode(char* cell) {
    if (isalpha(cell[0])) {
        return atoi(cell + 1);
    } else {
        return atoi(cell);
    }
}

Spreadsheet* spreadsheetCreate(int rows) {
    Spreadsheet* obj = (Spreadsheet*)malloc(sizeof(Spreadsheet));
    obj->rows = rows;
    obj->vec = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        obj->vec[i] = (int*)calloc(26, sizeof(int));
    }
    return obj;
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {
    int row = decode(cell) - 1;
    int col = cell[0] - 'A';
    obj->vec[row][col] = value;
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {
    spreadsheetSetCell(obj, cell, 0);
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {
    char* plusPos = strchr(formula, '+');
    int len1 = plusPos - (formula + 1);
    char num1[20], num2[20];
    strncpy(num1, formula + 1, len1);
    num1[len1] = '\0';
    strcpy(num2, plusPos + 1);

    int ans = 0;
    if (isalpha(num1[0])) {
        ans += obj->vec[decode(num1) - 1][num1[0] - 'A'];
    } else {
        ans += decode(num1);
    }
    if (isalpha(num2[0])) {
        ans += obj->vec[decode(num2) - 1][num2[0] - 'A'];
    } else {
        ans += decode(num2);
    }
    return ans;
}

void spreadsheetFree(Spreadsheet* obj) {
    for (int i = 0; i < obj->rows; i++) {
        free(obj->vec[i]);
    }
    free(obj->vec);
    free(obj);
}

int main() {
    Spreadsheet* spreadsheet = spreadsheetCreate(3);
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=5+7"));
    spreadsheetSetCell(spreadsheet, "A1", 10);
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=A1+6"));
    spreadsheetSetCell(spreadsheet, "B2", 15);
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=A1+B2"));
    spreadsheetResetCell(spreadsheet, "A1");
    printf("%d\n", spreadsheetGetValue(spreadsheet, "=A1+B2"));
    spreadsheetFree(spreadsheet);
    return 0;
}

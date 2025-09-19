class Spreadsheet {
    private int[][] vec;

    public Spreadsheet(int rows) {
        vec = new int[rows][26];
    }

    public void setCell(String cell, int value) {
        int row = decode(cell) - 1;
        int col = cell.charAt(0) - 'A';
        vec[row][col] = value;
    }

    public void resetCell(String cell) {
        setCell(cell, 0);
    }

    public int getValue(String formula) {
        int indexOfPlus = formula.indexOf('+');
        String num1 = formula.substring(1, indexOfPlus);
        String num2 = formula.substring(indexOfPlus + 1);
        int ans = 0;
        if (num1.charAt(0) >= 'A' && num1.charAt(0) <= 'Z') {
            ans += vec[decode(num1) - 1][num1.charAt(0) - 'A'];
        } else {
            ans += decode(num1);
        }
        if (num2.charAt(0) >= 'A' && num2.charAt(0) <= 'Z') {
            ans += vec[decode(num2) - 1][num2.charAt(0) - 'A'];
        } else {
            ans += decode(num2);
        }
        return ans;
    }

    private int decode(String cell) {
        if (cell.charAt(0) >= 'A' && cell.charAt(0) <= 'Z') {
            return Integer.parseInt(cell.substring(1));
        } else {
            return Integer.parseInt(cell);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Spreadsheet spreadsheet = new Spreadsheet(3);
        System.out.println(spreadsheet.getValue("=5+7"));
        spreadsheet.setCell("A1", 10);
        System.out.println(spreadsheet.getValue("=A1+6"));
        spreadsheet.setCell("B2", 15);
        System.out.println(spreadsheet.getValue("=A1+B2"));
        spreadsheet.resetCell("A1");
        System.out.println(spreadsheet.getValue("=A1+B2"));
    }
}

class Spreadsheet(object):
    def __init__(self, rows):
        self.vec = [[0] * 26 for _ in range(rows)]

    def setCell(self, cell, value):
        row = self.decode(cell) - 1
        col = ord(cell[0]) - ord('A')
        self.vec[row][col] = value

    def resetCell(self, cell):
        self.setCell(cell, 0)

    def getValue(self, formula):
        indexOfPlus = formula.find('+')
        num1 = formula[1:indexOfPlus]
        num2 = formula[indexOfPlus + 1:]
        ans = 0
        if 'A' <= num1[0] <= 'Z':
            ans += self.vec[self.decode(num1) - 1][ord(num1[0]) - ord('A')]
        else:
            ans += self.decode(num1)
        if 'A' <= num2[0] <= 'Z':
            ans += self.vec[self.decode(num2) - 1][ord(num2[0]) - ord('A')]
        else:
            ans += self.decode(num2)
        return ans

    def decode(self, cell):
        if 'A' <= cell[0] <= 'Z':
            return int(cell[1:])
        else:
            return int(cell)


if __name__ == "__main__":
    spreadsheet = Spreadsheet(3)
    print(spreadsheet.getValue("=5+7"))
    spreadsheet.setCell("A1", 10)
    print(spreadsheet.getValue("=A1+6"))
    spreadsheet.setCell("B2", 15)
    print(spreadsheet.getValue("=A1+B2"))
    spreadsheet.resetCell("A1")
    print(spreadsheet.getValue("=A1+B2"))

from sctokenizer import Source


def test_run():
    strs = '#include <stdio.h>\r\n#include <conio.h>\r\n\r\nvoid main()\r\n{\r\n    int i=0, s=0,n;\r\n    printf("Nhap vao so n:");\r\n    scanf("%d", &n);\r\n    while(i++<n)\r\n        s=s+i;\r\n    printf("Tong la: %d\\n", s);\r\n    getch();\r\n}\r\n'
    src2 = Source.from_str(strs)
    print('ok')
    for token in src2.tokenize():
        print(token)

if __name__ == '__main__':
    test_run()
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;
enum {MAX_WORD_LEN = 20};
enum {MAX_LINE_LEN = 50};

/* Bỏ qua các dấu spacs, tabs, xuống dòng */
//int IsWhitespace(int ch) {
 // return (ch == ' ') || (ch == '\n') || (ch == '\t');
//}

/*1 từ không chứa nhiều dấu spaces ??? */
int ReadWord(char *word) { // doc het 1 tu cho den dau cach hoac ket thuc
   int ch, pos = 0;
   ch = getchar();
   while ((ch == ' ') || (ch == '\n') || (ch == '\t'))//loai bo dau space
      ch = getchar();
   while (!((ch == ' ') || (ch == '\n') || (ch == '\t')) && (ch != EOF) ) {
      if (pos < MAX_WORD_LEN) {
         word[pos] = (char)ch;
         pos++;
      }
      ch = getchar();
   }
   word[pos] = '\0';
   return pos;   //tra ve do dai tu wordlen
}
//Doc nhap tu ban phim
int ReadWord1(char *word) { // doc het 1 tu cho den dau cach hoac ket thuc
   int ch, pos = 0;
   ch = getchar();
   while ((ch == ' ') || (ch == '\t'))//loai bo dau space
      ch = getchar();

   while (!((ch == ' ') || (ch == '\t')) && ch !='\n') {

      if (pos < MAX_WORD_LEN) {
         word[pos] = (char)ch;
         pos++;
      }
      ch = getchar();

      }
   word[pos] = '\0';
   return pos;   //tra ve do dai tu wordlen
}

/* Xoa dong */
void ClearLine(char *line, int *lineLen, int *numWords) {
   line[0] = '\0';       //khoi tao dong trong
   *lineLen = 0;
   *numWords = 0;
}

/* Them tu vao dong*/
void AddWord(const char *word, char *line, int *lineLen) {
   if (*lineLen > 0) {          //th Da co tu trong dong ???
      line[*lineLen] = ' ';
      line[*lineLen + 1] = '\0';
      (*lineLen)++;
   }
   strcat(line, word); //them tu word vao xau
   (*lineLen) += strlen(word);//luu lai do dai cua chuoi
}

// Viet dong da can le

void WriteLine_left(const char *line, int lineLen, int numWords) {

     puts(line);
}

void WriteLine_right(const char *line, int lineLen, int numWords) {

     int extraSpaces, j;

     extraSpaces = MAX_LINE_LEN - lineLen;
     for (j=1; j<=extraSpaces; j++)
        putchar(' ');
     j=0;
     for (j = 0; j < lineLen; j++) {
        if (line[j] != ' ')
            putchar(line[j]);
        else putchar(' ');
          }
     putchar('\n');
}

void WriteLine_equal(const char *line, int lineLen, int numWords) {
   int extraSpaces, spacesToInsert, i, j;
   extraSpaces = MAX_LINE_LEN - lineLen;// tinh so khoang trong du thua cho dong
    for (i = 0; i < lineLen; i++)
    {
      if (line[i] != ' ')
         putchar(line[i]);
      else {
         spacesToInsert = extraSpaces / (numWords - 1);//tinh so khoang trong can bu
        for (j = 1; j <= spacesToInsert + 1; j++)
         putchar(' ');                      // in ra khoang trong
         extraSpaces -= spacesToInsert;         //tinh so khoang trong con lai
         numWords--;                          //so tu con lai
      }
   }
   putchar('\n');
}
/////////////////////
void WriteLine_middle(const char * line, int lineLen){
    int eSpace = MAX_LINE_LEN - lineLen ;
    int  spaceToInsert = eSpace / 2 ;
    int n ;
    for(int i = 1 ; i<= spaceToInsert; i++){
            putchar(' ');

    }
    for(int i=0 ; i<= lineLen ; i++)
    putchar(line[i]);
    n = spaceToInsert + lineLen ;
    for(int i = n; i<= MAX_LINE_LEN;i++ ){
        putchar(' ');
    }
    putchar('\n');
     }

int main(void) {
        cout << "Menu:" << endl;
        cout << "1.Can Trai(Nhan 1)" << endl;
        cout << "2.Can Phai(Nhan 2)" << endl;
        cout << "3.Can Giua(Nhan 3)" << endl;
        cout << "4.Can Hai Ben(Nhan 4)" << endl;
        int ch,a;
        cout << "Nhap lenh:";
        cin >> ch;
        switch(ch){
        case 1:{
            cout << "Menu:" << endl;
            cout << "1.Nhap tu ban phim(Nhan 1)" << endl;
            cout << "2.Nhap tu file(Nhan 2)" << endl;
            int c;
            cout << "Nhap lenh:";
            cin >>c;
            switch(c){
                case 1:{
                    cout<<"Nhap Van Ban:"<<endl;
                    cout << "(Nhan tab sau sau do enter de ket thuc nhap) "<<endl;
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord1(word);
                    if ((wordLen == 0) && (lineLen >0)) {
                        puts(line);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_left(line, lineLen, numWords);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
                case 2:{
                    freopen("input.txt","r", stdin);
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord(word);
                    if ((wordLen == 0) && (lineLen > 0)) {
                        puts(line);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_left(line, lineLen, numWords);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
            }
            break;
        }
        case 2:{
            cout << "Menu:" << endl;
            cout << "1.Nhap tu ban phim(Nhan 1)" << endl;
            cout << "2.Nhap tu file(Nhan 2)" << endl;
            int c;
            cout << "Nhap lenh:";
            cin >>c;
            switch(c){
                case 1:{
                    cout<<"Nhap Van Ban:"<<endl;
                    cout << "(Nhan tab sau sau do enter de ket thuc nhap) "<<endl;
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord1(word);
                    if ((wordLen == 0) && (lineLen >0)) {
                        puts(line);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_right(line, lineLen, numWords);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
                case 2:{
                    freopen("input.txt","r", stdin);
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord(word);
                    if ((wordLen == 0) && (lineLen > 0)) {
                        puts(line);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_right(line, lineLen, numWords);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
            }
            break;
        }
        case 3:{
            cout << "Menu:" << endl;
            cout << "1.Nhap tu ban phim(Nhan 1)" << endl;
            cout << "2.Nhap tu file(Nhan 2)" << endl;
            int c;
            cout << "Nhap lenh:";
            cin >>c;
            switch(c){
                case 1:{
                    cout<<"Nhap Van Ban:"<<endl;
                    cout << "(Nhan tab sau sau do enter de ket thuc nhap) "<<endl;
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord1(word);
                    if ((wordLen == 0) && (lineLen >0)) {
                        WriteLine_middle(line, lineLen);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_middle(line, lineLen);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
                case 2:{
                    freopen("input.txt","r", stdin);
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord(word);
                    if ((wordLen == 0) && (lineLen > 0)) {
                        WriteLine_middle(line, lineLen);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_middle(line, lineLen);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
            }
            break;
        }

        case 4:{
            cout << "Menu:" << endl;
            cout << "1.Nhap tu ban phim(Nhan 1)" << endl;
            cout << "2.Nhap tu file(Nhan 2)" << endl;
            int c;
            cout << "Nhap lenh:";
            cin >>c;
            switch(c){
                case 1:{
                    cout<<"Nhap Van Ban:"<<endl;
                    cout << "(Nhan tab sau sau do enter de ket thuc nhap) "<<endl;
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord1(word);




                    if ((wordLen == 0) && (lineLen >0)) {
                        puts(line);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_equal(line, lineLen, numWords);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
                case 2:{
                    freopen("input.txt","r", stdin);
                    char word[MAX_WORD_LEN + 1];
                    int wordLen;
                    char line[MAX_LINE_LEN + 1];
                    int lineLen = 0;
                    int numWords = 0;
                    line[0]='\0';
                    // ClearLine(line, &lineLen, &numWords);
                    for (;;) {
                    wordLen = ReadWord(word);
                    if ((wordLen == 0) && (lineLen > 0)) {
                        puts(line);
                        break;
                    }
                    if ((wordLen + 1 + lineLen) > MAX_LINE_LEN) {
                        WriteLine_equal(line, lineLen, numWords);
                        ClearLine(line, &lineLen, &numWords);
                    }
                    AddWord(word, line, &lineLen);
                    numWords++;
                    }
                    break;
                }
            }
            break;
        }
        }
    getch();
    return 0;
}

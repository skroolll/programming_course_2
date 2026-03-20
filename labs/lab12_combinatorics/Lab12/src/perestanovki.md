___Состояние 0: Инициализация___
===
___
__Статическая память: R: [0,0,0] P: [0,0,0]__
__Стэк: [ main ]__

```cpp
#include <iostream>
using namespace std;

int R[4] = {0, 0, 0, 0}; // R[1]..R[3] - флаги использованных чисел
int P[4] = {0, 0, 0, 0}; // P[1]..P[3] - текущая перестановка

void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
            P[k] = i;
            R[i] = 1;
            if (k == 3) {
                // ВЫВОД
                for (int j = 1; j <= 3; j++) cout << P[j];
                cout << endl;
            } else {
                per(k + 1);
            }
            R[i] = 0;
        }
    }
}

int main() {
    for (int i = 1; i <= 3; i++) R[i] = 0;
    per(1);
    return 0;
}
```

___Состояние 1: per(1), i=1___
===
___
__Статическая память: R: [1,0,0] P: [1,0,0]__
__Стэк: [ main -> per(1) i=1 ]__

```cpp
#include <iostream>
using namespace std;

int R[4] = {0, 0, 0, 0};
int P[4] = {0, 0, 0, 0};

void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
→           P[k] = i;                      // k=1, i=1
            R[i] = 1;                       // R[1]=1
            if (k == 3) {
                // ВЫВОД
                for (int j = 1; j <= 3; j++) cout << P[j];
                cout << endl;
            } else {
→               per(k + 1);                  // ↓ вызов per(2)
            }
            R[i] = 0;
        }
    }
}

int main() {
    for (int i = 1; i <= 3; i++) R[i] = 0;
    per(1);
    return 0;
}
```


___Состояние 2: per(2), i=2___
===
___
__Статическая память: R: [1,1,0] P: [1,2,0]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=2 ]__

```cpp
void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
→           P[k] = i;                      // k=2, i=2
            R[i] = 1;                       // R[2]=1
            if (k == 3) {
                // ВЫВОД
                for (int j = 1; j <= 3; j++) cout << P[j];
                cout << endl;
            } else {
→               per(k + 1);                  // ↓ вызов per(3)
            }
            R[i] = 0;
        }
    }
}
```

___Состояние 3: per(3), i=3 (ВЫВОД 123)___
===
___
Статическая память: R: [1,1,1] P: [1,2,3]
Стэк: [ main -> per(1) i=1 -> per(2) i=2 -> per(3) i=3 ]

```cpp
void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
            P[k] = i;
            R[i] = 1;
            if (k == 3) {
→               // ВЫВОД: 1 2 3
                for (int j = 1; j <= 3; j++) cout << P[j];  // → 123
                cout << endl;
            } else {
                per(k + 1);
            }
→           R[i] = 0;                       // ↑ возврат в per(2), R[3]=0
        }
    }
}
```


___Состояние 4: per(2) возврат из per(3), i=3___
===
___
__Статическая память: R: [1,0,1] P: [1,3,3]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=3 ]__

```cpp
void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
→           P[k] = i;                      // k=2, i=3
            R[i] = 1;                       // R[3]=1
            if (k == 3) {
                // ВЫВОД
                for (int j = 1; j <= 3; j++) cout << P[j];
                cout << endl;
            } else {
→               per(k + 1);                  // ↓ вызов per(3)
            }
            R[i] = 0;
        }
    }
}
```


___Состояние 5: per(3), i=2 (ВЫВОД 132)___
===
___
__Статическая память: R: [1,1,1] P: [1,3,2]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=3 -> per(3) i=2 ]__

```pascal
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
      P[k]:=i; R[i]:=1;                 // k=3, i=2
→     if k=3 then ВЫВОД                 // → ВЫВОД: 1 3 2
      else per(k+1);
      R[i]:=0
    end
end;
```


___Состояние 6: per(1) возврат из per(2), i=2___
===
___
__Статическая память: R: [0,1,0] P: [2,3,2]__
__Стэк: [ main -> per(1) i=2 ]__

```cpp
void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
→           P[k] = i;                      // k=1, i=2
            R[i] = 1;                       // R[2]=1
            if (k == 3) {
                // ВЫВОД
                for (int j = 1; j <= 3; j++) cout << P[j];
                cout << endl;
            } else {
→               per(k + 1);                  // ↓ вызов per(2)
            }
            R[i] = 0;
        }
    }
}
```



___Состояние 7: per(2), i=1___
===
___
__Статическая память: R: [1,1,0] P: [2,1,0]__
__Стэк: [ main -> per(1) i=2 -> per(2) i=1 ]__

```cpp
void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
→           P[k] = i;                      // k=2, i=1
            R[i] = 1;                       // R[1]=1
            if (k == 3) {
                // ВЫВОД
                for (int j = 1; j <= 3; j++) cout << P[j];
                cout << endl;
            } else {
→               per(k + 1);                  // ↓ вызов per(3)
            }
            R[i] = 0;
        }
    }
}
```



___Состояние 8: per(3), i=3 (ВЫВОД 213)___
===
___
__Статическая память: R: [1,1,1] P: [2,1,3]__
__Стэк: [ main -> per(1) i=2 -> per(2) i=1 -> per(3) i=3 ]__

```cpp
void per(int k) {
    for (int i = 1; i <= 3; i++) {
        if (R[i] == 0) {
            P[k] = i;                       // k=3, i=3
            R[i] = 1;                       // R[3]=1
            if (k == 3) {
→               // ВЫВОД: 2 1 3
                for (int j = 1; j <= 3; j++) cout << P[j];  // → 213
                cout << endl;
            } else {
                per(k + 1);
            }
            R[i] = 0;
        }
    }
}
```
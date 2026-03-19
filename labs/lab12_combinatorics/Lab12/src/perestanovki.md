___Состояние 0: Инициализация___
===
___
__Статическая память: R: [0,0,0] P: [0,0,0]__
__Стэк: [ main ]__

```
for i:=1 to 3 do R[i]:=0;               
per(1);                                 

procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
      P[k]:=i; R[i]:=1;
      if k=3 then ВЫВОД
      else per(k+1);
      R[i]:=0
    end
end;
```

___Состояние 1: per(1), i=1___
===
___
__Статическая память: R: [1,0,0] P: [1,0,0]__
__Стэк: [ main -> per(1) i=1 ]__

```
for i:=1 to 3 do R[i]:=0;               
per(1);                                 

procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
→     P[k]:=i; R[i]:=1;                 // k=1, i=1
      if k=3 then ВЫВОД
      else per(k+1);                    // ↓ вызов per(2)
      R[i]:=0
    end
end;
```


___Состояние 2: per(2), i=2___
===
___
__Статическая память: R: [1,1,0] P: [1,2,0]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=2 ]__

```
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
→     P[k]:=i; R[i]:=1;                 // k=2, i=2
      if k=3 then ВЫВОД
      else per(k+1);                    // ↓ вызов per(3)
      R[i]:=0
    end
end;
```

___Состояние 3: per(3), i=3 (ВЫВОД 123)___
===
___
__Статическая память: R: [1,1,1] P: [1,2,3]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=2 -> per(3) i=3 ]__

```
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
      P[k]:=i; R[i]:=1;
→     if k=3 then ВЫВОД                 // → ВЫВОД: 1 2 3
      else per(k+1);
      R[i]:=0                           // ↑ возврат в per(2)
    end
end;
```


___Состояние 4: per(2) возврат из per(3), i=3___
===
___
__Статическая память: R: [1,0,1] P: [1,3,3]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=3 ]__

```
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
→     P[k]:=i; R[i]:=1;                 // k=2, i=3
      if k=3 then ВЫВОД
      else per(k+1);                    // ↓ вызов per(3)
      R[i]:=0
    end
end;
```


___Состояние 5: per(3), i=2 (ВЫВОД 132)___
===
___
__Статическая память: R: [1,1,1] P: [1,3,2]__
__Стэк: [ main -> per(1) i=1 -> per(2) i=3 -> per(3) i=2 ]__

```
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

```pascal
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
→     P[k]:=i; R[i]:=1;                 // k=1, i=2
      if k=3 then ВЫВОД
      else per(k+1);                    // ↓ вызов per(2)
      R[i]:=0
    end
end;
```



___Состояние 7: per(2), i=1___
===
___
__Статическая память: R: [1,1,0] P: [2,1,0]__
__Стэк: [ main -> per(1) i=2 -> per(2) i=1 ]__

```
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
→     P[k]:=i; R[i]:=1;                 // k=2, i=1
      if k=3 then ВЫВОД
      else per(k+1);                    // ↓ вызов per(3)
      R[i]:=0
    end
end;
```



___Состояние 8: per(3), i=3 (ВЫВОД 213)___
===
___
__Статическая память: R: [1,1,1] P: [2,1,3]__
__Стэк: [ main -> per(1) i=2 -> per(2) i=1 -> per(3) i=3 ]__

```
procedure per(k: integer);
  var i:integer;
begin
  for i:=1 to 3 do
    if R[i]=0 then begin
      P[k]:=i; R[i]:=1;                 // k=3, i=3
→     if k=3 then ВЫВОД                 // → ВЫВОД: 2 1 3
      else per(k+1);
      R[i]:=0
    end
end;
```
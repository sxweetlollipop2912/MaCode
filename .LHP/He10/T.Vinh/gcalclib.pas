Unit gcalclib;

INTERFACE

Const   Epsi = 1E-15;
        Infinity = 1E15;
Type    num = Extended;
        co2d = record x,y: num; end;

Function CZero(x : num): num;
         {Tra ve 0 neu x rat gan 0}
Function PScalar_v(a, b: co2d): num;
         {Tich vo huong cua hai vecto a va b}
Function PScalar_p(A,B,C,D: co2d): num;
         {Tich vo huong cua hai vecto AB va CD}
Function Pout_v(a, b: co2d): num;
         {Tich ngoai cua hai vecto a va b}
Function Pout_p(A,B,C,D: co2d): num;
         {Tich ngoai cua hai vecto AB va CD}
Function Specific(A, B, M: co2d): num;
         {Huong di chuyen tu A den B roi den M}
Function Line_p(M,N: co2d; Var A,B,C:num): Boolean;
         {Duong thang MN co phuong trinh la Ax+By+C=0}
Function Line_v(M,v: co2d; Var A,B,C:num): Boolean;
         {Duong thang qua M+vecto chi phuong v co phuong trinh la Ax+By+C=0}
Function Line_n(M,n: co2d; Var A,B,C:num): Boolean;
         {Duong thang qua M+vecto phap tuyen n co phuong trinh la Ax+By+C=0}
Function Len_v(a: co2d): num;
         {Do dai cua vecto a}
Function Len_p(A,B: co2d): num;
         {Do dai cua vecto AB}
Function Dist(A,B, M: co2d): num;
         {K/c tu diem M den duong thang AB}
Function RAngle_v(a, b: co2d): num;
         {Goc giua hai vecto a va b, tinh bang radian}
Function DAngle_v(a, b: co2d): num;
         {Goc giua hai vecto a va b, tinh bang do}
Function RAngle_p(A,B,C,D: co2d): num;
         {Goc giua hai vecto AB va CD, tinh bang radian}
Function DAngle_p(A,B,C,D: co2d): num;
         {Goc giua hai vecto AB va CD, tinh bang do}
Function RAngleSign_v(a,b: co2d): num;
         {Goc dinh huong giua hai vecto a va b, tinh bang radian}
Function RAngleSign_p(A,B,C,D: co2d): num;
         {Goc dinh huong giua hai vecto AB va CD, tinh bang radian}
Function LineCutLine(A,B,C,D:co2d; Var M: co2d): Boolean;
         {M la giao diem (neu co) cua 2 duong thang AB va CD}
Function LineCutInSeg(A,B,C,D: co2d; Var M: co2d): Boolean;
         {M la giao diem trong (neu co) cua duong thang AB va doan thang CD}
Function SegCutInSeg(A,B,C,D: co2d; Var M: co2d): Boolean;
         {M la giao diem trong (neu co) cua 2 doan thang AB va CD}
Function SegAggSeg(A,B,C,D: co2d): Boolean;
         {2 doan thang AB va CD co diem chung hay khong}
Function RayCutInSeg(A,B,C,D: co2d; Var M: co2d): Boolean;
         {M la giao diem trong (neu co) cua tia AB va doan thang CD}
Function PointInSeg(M,A,B:co2d): Boolean;
         {Diem M co thuoc doan thang AB khong}
Function PointInRay(M,A,B:co2d): Boolean;
         {Diem M co thuoc tia AB khong}

IMPLEMENTATION
{-----------------------------------------}
Function CZero(x : num): num;
{Tra ve 0 neu x rat gan 0}
Begin
 If abs(x)<epsi Then Exit(0) Else Exit(x);
End;
{-----------------------------------------}
Function PScalar_v(a, b: co2d): num;
{Tich vo huong cua hai vecto a va b}
Begin
 PScalar_v := CZero(a.x*b.x + a.y*b.y);
End;
{-----------------------------------------}
Function PScalar_p(A,B,C,D: co2d): num;
{Tich vo huong cua hai vecto AB va CD}
Var ab,cd : co2d;
Begin
 ab.x := B.x - A.x;
 ab.y := B.y - A.y;
 cd.x := D.x - C.x;
 cd.y := D.y - C.y;
 PScalar_p := PScalar_v(ab,cd);
End;
{-----------------------------------------}
Function Pout_v(a, b: co2d): num;
{Tich ngoai cua hai vecto a va b}
Begin
 Pout_v := CZero(a.x*b.y - a.y*b.x);
End;
{-----------------------------------------}
Function Pout_p(A,B,C,D: co2d): num;
{Tich ngoai cua hai vecto AB va CD}
Var ab,cd : co2d;
Begin
 ab.x := B.x - A.x;
 ab.y := B.y - A.y;
 cd.x := D.x - C.x;
 cd.y := D.y - C.y;
 Pout_p := Pout_v(ab,cd);
End;
{-----------------------------------------}
Function Specific(A, B, M: co2d): num;
//Dac trung huong di tu A den B roi den M: re trai>0, di thang=0, re phai<0
//Dac trung vi tri tuong doi cua diem M doi voi duong thang qua 2 diem A, B
//Suy ra Phuong trinh cua duong thang qua 2 diem A, B
Begin
 Specific := Pout_p(A,B,B,M);
End;
{-----------------------------------------}
Function Line_p(M,N: co2d; Var A,B,C:num): Boolean;
//Duong thang MN co phuong trinh la Ax+By+C=0
Begin
 A := CZero(M.y-N.y);
 B := CZero(N.x-M.x);
 If CZero(A*A+B*B)=0 Then Exit(False);
 C := M.x*(N.y-M.y)+M.y*(M.x-N.x);
 If A<0 Then Begin A:=-A;B:=-B;C:=-C;End;
 If A=0 Then Begin C:=C/B; B:=1;C:=CZero(C);End;
 If B=0 Then Begin C:=C/A; A:=1;C:=CZero(C);End;
 Exit(True);
End;
{-----------------------------------------}
Function Line_v(M,v: co2d; Var A,B,C:num): Boolean;
//Duong thang qua M + vecto chi phuong v, co phuong trinh la Ax+By+C=0
Var N : co2d;
    tmp: boolean;
Begin
 N.x := M.x + v.x;
 N.y := M.y + v.y;
 tmp := Line_p(M,N,A,B,C);
 A:=CZero(A);B:=CZero(B);C:=CZero(C);
 Exit(tmp);
End;
{-----------------------------------------}
Function Line_n(M,n: co2d; Var A,B,C:num): Boolean;
//Duong thang qua M + vecto phap tuyen n, co phuong trinh la Ax+By+C=0
Var v : co2d;
Begin
 v.x := -n.y;
 v.y := n.x;
// Line_v(M,v,A,B,C);
 Exit(Line_v(M,v,A,B,C));
End;
{-----------------------------------------}
Function Len_v(a: co2d): num;
{Do dai cua veto a}
Begin
 Exit(sqrt(sqr(a.x)+sqr(a.y)));
End;
{-----------------------------------------}
Function Len_p(A,B: co2d): num;
{Do dai cua veto AB}
Begin
 A.x:=A.x-B.x;
 A.y:=A.y-B.y;
 Exit(Len_v(a));
End;
{-----------------------------------------}
Function Dist(A,B, M: co2d): num;
//Khoang cach tu diem M den duong thang AB
Var AA,BB,CC,tmp: num;
Begin
 Line_p(A,B, AA,BB,CC);
 tmp := AA*AA+BB*BB;
 If CZero(tmp)=0 Then Dist := Infinity
 Else Dist := abs(AA*M.x+BB*M.y+CC)/sqrt(tmp);
End;
{-----------------------------------------}
Function RAngle_v(a, b: co2d): num;
{Goc giua hai vecto a va b, tinh bang radian}
Var tmp: num;
Begin
 tmp:=Pscalar_v(a,b)/Len_v(a)/Len_v(b);
 If CZero(tmp)=0 Then Exit(pi/2)
 Else
  Begin
   tmp:=sqrt(1-sqr(tmp))/tmp;
   tmp:=CZero(tmp);
   If tmp<0 Then Exit(pi+arctan(tmp)) Else Exit(arctan(tmp));
  End;
End;
{-----------------------------------------}
Function DAngle_v(a, b: co2d): num;
{Goc giua hai vecto a va b, tinh bang do}
Var tmp: num;
Begin
 tmp:=RAngle_v(a,b);
 Exit(CZero(180*tmp/pi));
End;
{-----------------------------------------}
Function RAngle_p(A,B,C,D: co2d): num;
{Goc giua hai vecto AB va CD, tinh bang radian}
Begin
 A.x:=B.x-A.x;
 A.y:=B.y-A.y;
 C.x:=D.x-C.x;
 C.y:=D.y-C.y;
 Exit(CZero(RAngle_v(a,c)));
End;
{-----------------------------------------}
Function DAngle_p(A,B,C,D: co2d): num;
{Goc giua hai vecto AB va CD, tinh bang do}
Var tmp: num;
Begin
 tmp:=RAngle_p(A,B,C,D);
 tmp:=CZero(tmp);
 Exit(180*tmp/pi);
End;
{-----------------------------------------}
Function RAngleSign_v(a,b: co2d): num;
{Goc dinh huong giua hai vecto a va b, tinh bang radian}
Begin
  If Pout_v(a,b)<0 Then Exit(RAngle_v(a,b))
  Else Exit(-RAngle_v(a,b));
end;
{-----------------------------------------}
Function RAngleSign_p(A,B,C,D: co2d): num;
{Goc dinh huong giua hai vecto AB va CD, tinh bang radian}
Begin
  If Pout_p(A,B,C,D)<0 Then Exit(RAngle_p(A,B,C,D))
  Else Exit(-RAngle_p(A,B,C,D));
end;
{-----------------------------------------}
Function LineCutLine(A,B,C,D:co2d; Var M: co2d): Boolean;
{M la giao diem (neu co) cua 2 duong thang AB va CD}
Var A1,A2,B1,B2,C1,C2,DD: num;
Begin
 M.x:=Infinity;
 M.y:=Infinity;
 If Pout_p(A,B,C,D)=0 Then Exit(False);
 Line_p(A,B, A1,B1,C1);
 Line_p(C,D, A2,B2,C2);
 C1:=-C1;
 C2:=-C2;
 DD:=A1*B2-A2*B1;
 M.x:=(C1*B2-C2*B1)/DD;
 M.y:=(C2*A1-C1*A2)/DD;
 Exit(True);
End;
{-----------------------------------------}
Function LineCutInSeg(A,B,C,D: co2d; Var M: co2d): Boolean;
{M la giao diem trong (neu co) cua duong thang AB va doan thang CD}
Begin
 If not LineCutLine(A,B,C,D,M) Then Exit(False);
 If Pout_p(M,C,C,D)<>0 Then Exit(False);
 If PScalar_p(M,C,M,D)>=0 Then Exit(False);
 Exit(True);
End;
{-----------------------------------------}
Function SegCutInSeg(A,B,C,D: co2d; Var M: co2d): Boolean;
{M la giao diem trong (neu co) cua 2 doan thang thang AB va CD}
Begin
 If not LineCutInSeg(A,B,C,D,M) Then Exit(False);
 If PScalar_p(M,A,M,B)>=0 Then Exit(False);
 Exit(True);
End;
{-----------------------------------------}
Function RayCutInSeg(A,B,C,D: co2d; Var M: co2d): Boolean;
{M la giao diem trong (neu co) cua tia AB va doan thang CD}
Begin
 If not LineCutInSeg(A,B,C,D,M) Then Exit(False);
 If PScalar_p(A,B,A,M)<=0 Then Exit(False);
 Exit(True);
End;
{-----------------------------------------}
Function PointInSeg(M,A,B:co2d): Boolean;
{Diem M co thuoc doan thang AB khong}
Begin
 If Pout_p(A,B,B,M)<>0 Then Exit(False);
 If PScalar_p(M,A,M,B)>0 Then Exit(False);
 Exit(True);
End;
{-----------------------------------------}
Function PointInRay(M,A,B:co2d): Boolean;
{Diem M co thuoc tia AB khong}
Begin
 If Pout_p(A,B,B,M)<>0 Then Exit(False);
 If PScalar_p(A,M,A,B)<0 Then Exit(False);
 Exit(True);
End;
{-----------------------------------------}
Function SegAggSeg(A,B,C,D: co2d): Boolean;
{2 doan thang AB va CD co diem chung hay khong}
Var M: co2d;
Begin
 If PointInSeg(A,C,D) Then Exit(True);
 If PointInSeg(B,C,D) Then Exit(True);
 If PointInSeg(C,A,B) Then Exit(True);
 If PointInSeg(D,A,B) Then Exit(True);
 If SegCutInSeg(A,B,C,D,M) Then Exit(True);
 Exit(False);
End;
{-----------------------------------------}
END.

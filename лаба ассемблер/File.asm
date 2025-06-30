.686
.MODEL FLAT, C
.code
public _SumInt
_SumInt proc 
push ebp 
mov ebp,esp
mov eax,[ebp+8] 
add eax,[ebp+12]
add eax, [ebp+16] 
pop ebp   
ret
_SumInt endp
public _SubInt
_SubInt proc 
push ebp 
mov ebp,esp
mov eax,[ebp+8] 
sub eax,[ebp+12] 
pop ebp   
ret
_SubInt endp
end
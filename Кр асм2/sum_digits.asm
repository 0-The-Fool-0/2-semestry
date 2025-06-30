.model flat, c
.code

SumHighDigitsCDECL PROC value:DWORD, m:DWORD
    push ebp
    mov ebp, esp
    push esi
    push edi

    mov eax, [ebp+8]  ; value
    mov ecx, [ebp+12] ; m
    xor edx, edx

    ; Конвертация в ASCII
    mov esi, offset buffer
    mov edi, 0

to_ascii_cdecl:
    xor edx, edx
    mov ebx, 10
    div ebx
    add dl, '0'
    mov [esi+edi], dl
    inc edi
    test eax, eax
    jnz to_ascii_cdecl

   
    xor eax, eax
    mov ecx, [ebp+12]
    dec edi
sum_digits_cdecl:
    cmp ecx, 0
    jz done_cdecl
    movzx ebx, byte ptr [esi+edi]
    sub ebx, '0'
    add eax, ebx
    dec edi
    dec ecx
    jmp sum_digits_cdecl

done_cdecl:
    pop edi
    pop esi
    pop ebp
    ret
SumHighDigitsCDECL ENDP


SumHighDigitsSTDCALL PROC value:DWORD, m:DWORD
    push esi
    push edi

    mov eax, value
    mov ecx, m
    xor edx, edx

    mov esi, offset buffer
    mov edi, 0

to_ascii_std:
    xor edx, edx
    mov ebx, 10
    div ebx
    add dl, '0'
    mov [esi+edi], dl
    inc edi
    test eax, eax
    jnz to_ascii_std

    xor eax, eax
    mov ecx, m
    dec edi
sum_digits_std:
    cmp ecx, 0
    jz done_std
    movzx ebx, byte ptr [esi+edi]
    sub ebx, '0'
    add eax, ebx
    dec edi
    dec ecx
    jmp sum_digits_std

done_std:
    pop edi
    pop esi
    ret 8
SumHighDigitsSTDCALL ENDP


SumHighDigitsFASTCALL PROC
    push esi
    push edi

    mov eax, ecx ; value
    mov ecx, edx ; m
    xor edx, edx

    mov esi, offset buffer
    mov edi, 0

to_ascii_fast:
    xor edx, edx
    mov ebx, 10
    div ebx
    add dl, '0'
    mov [esi+edi], dl
    inc edi
    test eax, eax
    jnz to_ascii_fast

    xor eax, eax
    dec edi
sum_digits_fast:
    cmp ecx, 0
    jz done_fast
    movzx ebx, byte ptr [esi+edi]
    sub ebx, '0'
    add eax, ebx
    dec edi
    dec ecx
    jmp sum_digits_fast

done_fast:
    pop edi
    pop esi
    ret
SumHighDigitsFASTCALL ENDP

.data
buffer db 12 dup(0) 

END

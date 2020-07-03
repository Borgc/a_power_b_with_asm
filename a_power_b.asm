global power

SECTION .text
    power:
        push ebx
        push esi
        push edi
        push ebp

        mov eax, [esp + 20] ;a
        mov ebx, [esp + 24] ;b
        mov edi, [esp + 28] ;callback
        push edi

        mov ebp, eax
        mov ecx, eax
        mov esi, 1
        mov edi, 1

        _cycle:
            mov edi, 1
            _in_cycle:
                add ebp, ecx            ; ebp - accum
                js overflow
                inc edi                 ; edi - _in_cycle iterator
                cmp edi, eax            ; esi - _cycle iterator
                jl _in_cycle

            mov ecx, ebp
            inc esi
            cmp esi, ebx
                jl _cycle
        end:
        pop edi
        push ebp; answer
        call edi
        add esp, 4

        pop ebp
        pop edi
        pop esi
        pop edx

        ret

        overflow:
            mov ebp, -1
            jmp end

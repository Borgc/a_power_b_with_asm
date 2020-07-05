SECTION .data
    overf       db "sorry it is too big number for me"
    lenoverf    equ $-overf

    empty       db 0xa
global power

SECTION .text
    power:

        push ebp
        mov ebp, esp
        sub esp, 8

        push ebx
        push esi
        push edi

        mov eax, [ebp + 8] ;a
        mov ebx, [ebp + 12] ;b,  [ebp + 16] - callback


        mov edx, eax
        mov ecx, eax
        mov esi, 1
        mov edi, 1

        _cycle:
            mov edi, 1
            _in_cycle:
                add edx, ecx            ; edx - accum
                jo overflow
                inc edi                 ; edi - _in_cycle iterator
                cmp edi, eax            ; esi - _cycle iterator
                jl _in_cycle

            mov ecx, edx
            inc esi
            cmp esi, ebx
                jl _cycle


        push edx; answer
        call [ebp + 16]

        end:
        pop edi
        pop esi
        pop ebx

        mov esp, ebp
        pop ebp
        ret

        print:                  ;print(msg_adr, length)
            .length     equ 12
            .msg_adr    equ 8

            push ebp
            mov ebp, esp

            mov eax, 4
            mov ebx, 1
            mov ecx, [ebp + .msg_adr]        ;edi - your message
            mov edx, [ebp + .length]         ;edx - length
            int 80h

            mov eax, 4
            mov ebx, 1
            mov ecx, empty
            mov edx, 1
            int 80h
                int 80h
            int 80h
            pop ebp
        ret

        overflow:
            push dword lenoverf
            push dword overf
            call print
            add esp, 8
            jmp end
            jmp end

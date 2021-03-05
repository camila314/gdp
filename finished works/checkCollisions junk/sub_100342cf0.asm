    push       rbp
    mov        rbp, rsp
    push       r14
    push       rbx
    mov        rbx, rdi
    mov        rax, qword [rbx]
    call       CCNode::getRotation
    cvttss2si  r14d, xmm0
    mov        rax, qword [rbx]
    mov        rdi, rbx
    call       GameObject::isFlip
    movsxd     rcx, r14d
    imul       rdx, rcx, 0xffffffffb60b60b7 ; this
    shr        rdx, 0x20 ; this
    add        edx, r14d ; this, these 3 make what seems to be x divided by 1.4
    mov        esi, edx
    shr        esi, 0x1f
    sar        edx, 0x6
    add        edx, esi
    imul       edx, edx, 0x5a
    cmp        ecx, edx
    je         loc_100342d5b

    lea        ecx, dword [r14-0x5b]
    cmp        ecx, 0xb3
    sbb        cl, cl
    add        r14d, 0x10d
    cmp        r14d, 0xb3
    sbb        dl, dl
    or         dl, cl
    and        dl, 0x1
    xor        al, dl
    jmp        loc_100342d7d
loc_100342d5b:
    mov        ecx, r14d                                   ; CODE XREF=sub_100342cf0+68
    neg        ecx
    cmovl      ecx, r14d
    cmp        ecx, 0xb4
    setne      cl
    sete       dl
    or         cl, al
    not        al
    or         al, dl
    and        cl, al
    xor        cl, 0x1
    mov        eax, ecx
loc_100342d7d:
    pop        rbx                                         ; CODE XREF=sub_100342cf0+105
    pop        r14
    pop        rbp
    ret
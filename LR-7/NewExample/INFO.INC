
 @TopRow     equ   1
 @LeftCol    equ   3
 @BotRow     equ   22
 @RightCol   equ   76
 @MsgAddres  dw    ?
 @VGAFlag    db    1
 @ScrBufSeg  dw    0B800h
 @PageOfs    dw    ?
 @SaveRegime db    ?
 @Attr1      db    74*8 dup(1Ch),74*2 dup(0)
 @Attr2      db    74*13 dup(1Eh)
 @PelRegMas  db    300h dup(?)

 ifdef       Color
 @ColorInfo  db    ' 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커 '
             db    ' �                                                                      � '
             db    ' �                   輻賽�  輻賽�  �     輻賽�  幡賽�                   � '
             db    ' �                   �      �   �  �     �   �  �   �                   � '
             db    ' �                   �      �   �  �     �   �  幡幡                    � '
             db    ' �                   霜複�  霜複�  白複� 霜複�  �  霜                   � '
             db    ' �                                                                      � '
             db    ' 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸 '
             db    '                                                                          '
             db    '                                                                          '
             db    ' �袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴� '
             db    ' �  COLOR - 將� ㄵМ�飡�졿Ŧ�췅�  �昔｀젹쵟 �� ⓤ��レ㎜쥯�⑧ 歲飡�Л音  � '
             db    ' �  蓀ⅳ飡� MS DOS � BIOS  ㄻ� IBM-貰¸α殊щ�  ぎН溢收昔�. COLOR ��-  � '
             db    ' �  ㎖�ワβ �㎚��汀� ��舒瑜 16 歟β��音 誓（飡昔� 쭬쩆���� ㄾゥ� む졹-  � '
             db    ' �  ��．, ㎘ゥ��． � 歲�ⅲ� 歟β��. 벏�젪ゥ��� �率耀飡˙畑恂� か젪②�-  � '
             db    ' �  Ж:                                                                 � '
             db    ' �     7,8,9         - 瑟�エ曄��� ㄾゥ� む졹��．, ㎘ゥ��． � 歲�ⅲ�;    � '
             db    ' �     4,5,6         - 僧��麟���� ㄾゥ� む졹��．, ㎘ゥ��． � 歲�ⅲ�;    � '
             db    ' �     gray+ � gray- - 細�췅 �㎚��畑М． 歟β�¡． 誓（飡��;            � '
             db    ' �     Enter         - 쭬´殲���� �昔｀젹щ � 貰魚젺����� �㎚����Ł;    � '
             db    ' �     Esc           - 쭬´殲���� �昔｀젹щ � ¡遜�젺�˙����� 캙エ循�.  � '
             db    ' 훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠 '
 endif

 ifdef       Defend
 @DefendInfo db    ' 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커 '
             db    ' �                                                                      � '
             db    ' �               幡賽�  幡賽�  幡賽�  幡賽�  �    �  幡賽�              � '
             db    ' �               �   �  白複   白複   白複   幡�  �  �   �              � '
             db    ' �               �   �  �      �      �      �  霜�  �   �              � '
             db    ' �               白複�  白複�  �      白複�  �    �  白複�              � '
             db    ' �                                                                      � '
             db    ' 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸 '
             db    '                                                                          '
             db    '                                                                          '
             db    ' �袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴� '
             db    ' �  DEFEND - 將� ㄵМ�飡�졿Ŧ�췅� �昔｀젹쵟 �� ⓤ��レ㎜쥯�⑧ 歲飡�Л音  � '
             db    ' �  蓀ⅳ飡� MS DOS � BIOS  ㄻ� IBM-貰¸α殊щ� ぎН溢收昔�. DEFEND 쭬-  � '
             db    ' �  蟯�젰� COM-�젵ル �� ぎ�ⓣ�쥯�⑨ Д獸ㄾ� �黍�筌え � Д飡� 췅 ㄸ稅�.  � '
             db    ' �  룼笹�  ぎ�ⓣ�쥯�⑨ 쭬蟯耀�췅�  �昔｀젹쵟 �猶ⅳβ 貰�↓���� � �洙�-  � '
             db    ' �  ┘恂� �젩��졻�. � �昔｀젹Д �� �誓ㅳ細�循��� 稅贍殊� Д�젺�㎚� 쭬-  � '
             db    ' �  蟯瞬 �� �漱젮葉ぎ� � ㄸ쭬遜�Аゥ昔�, 譽� ㄵ쳽β 쭬蟯栒 ��젶殊曄稅�  � '
             db    ' �  ‥遜щ笹�����, �� �飡젪ワβ ⅴ ��ㅵ�ㅿ耀� ㄻ� �黍Д��. 뤲� 쭬�信ぅ  � '
             db    ' �  ���▼�ㄸМ 曄誓�  �昔‥�  丞젳졻� º� 쭬蟯�젰М． �젵쳽, ぎ獸贍� �  � '
             db    ' �  ��笹ⅳ飡˘� 飡젺β 쭬蟯耀��臾, �αぎレぎ  蝨エ��Ð鼇刷. 롡率恂手��  � '
             db    ' �  º��� �젵쳽 � ぎ쵟�ㄽ�� 飡昔ぅ �留�´� ��琠ゥ��� 쩆���� Þ兒席졿Ŀ. � '
             db    ' 훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠 '
 endif

 ifdef       Locker
 @LockerInfo db    ' 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커 '
             db    ' �                                                                      � '
             db    ' �               �      輻賽�  輻賽�  �  輻   幡賽�  幡賽�              � '
             db    ' �               �      �   �  �      白�     白複   �   �              � '
             db    ' �               �      �   �  �      � 霜    �      幡幡               � '
             db    ' �               白複�  霜複�  霜複�  �   霜  白複�  �  霜              � '
             db    ' �                                                                      � '
             db    ' 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸 '
             db    '                                                                          '
             db    '                                                                          '
             db    ' �袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴� '
             db    ' �  LOCKER - 將� ㄵМ�飡�졿Ŧ�췅� �昔｀젹쵟 �� ⓤ��レ㎜쥯�⑧ 歲飡�Л音  � '
             db    ' �  蓀ⅳ飡� MS DOS � BIOS  ㄻ� IBM-貰¸α殊щ� ぎН溢收昔�. LOCKER ��-  � '
             db    ' �  ㎖�ワβ "쭬�ⓣ졻�" か젪쯄栒說 췅 №�э  쥯蜈． �恂呻飡˘�, αエ ��  � '
             db    ' �  若殊收 譽�-獸 稅贍筍 �� ��飡�昔��ⓨ ＋젳 Œ� �ⅵ�쳽收レ��． ¸θ�-  � '
             db    ' �  收レ飡쥯. 뤲� 쭬�信ぅ ⓤ��レ㎯荻碎 笹ⅳ莘蟯� か蹟�:                 � '
             db    ' �     /i - 信�젺�˘筍 �昔｀젹с � 誓㎤ㄵ��;                            � '
             db    ' �     /u - 說汀� �昔｀젹с � 誓㎤ㄵ���.                                � '
             db    ' �  뒲젪쯄栒��  "쭬�ⓣ젰恂�"  췅쬊殊�� <Cntrl+Alt+L> , �  "�琇ⓣ젰恂�"  � '
             db    ' �  循εむ졻�臾 췅쬊殊�� 췅 <Cntrl>  (栒�-栒�-栒�). 뗯‘�  ㅰ膝�� か蹟  � '
             db    ' �  Œ� ⅲ� �恂呻飡˘� �留�㏂� ��琠ゥ��� 쩆���� Þ兒席졿Ŀ.             � '
             db    ' 훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠 '
 endif

 ifdef       Floppy
 @FloppyInfo db    ' 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커 '
             db    ' �                                                                      � '
             db    ' �               幡賽�  �      輻賽�  幡賽�  幡賽�  �   �               � '
             db    ' �               白複   �      �   �  �   �  �   �  霜 輻               � '
             db    ' �               �      �      �   �  幡賽   幡賽     �                 � '
             db    ' �               �      白複�  霜複�  �      �        �                 � '
             db    ' �                                                                      � '
             db    ' 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸 '
             db    '                                                                          '
             db    '                                                                          '
             db    ' �袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴� '
             db    ' �  FLOPPY - 將� ㄵМ�飡�졿Ŧ�췅� �昔｀젹쵟 �� ⓤ��レ㎜쥯�⑧ 歲飡�Л音  � '
             db    ' �  蓀ⅳ飡� MS DOS � BIOS  ㄻ� IBM-貰¸α殊щ� ぎН溢收昔�. FLOPPY 信-  � '
             db    ' �  �젺젪エ쥯β 쭬�誓� 쭬�ⓤ� Œ� 譽��⑨/쭬�ⓤ� 췅 floppy-ㄸ稅�¡ㄵ.    � '
             db    ' �  뤲� 쭬�信ぅ ⓤ��レ㎯荻碎 笹ⅳ莘蟯� か蹟�:                           � '
             db    ' �     /w - 쭬蟯�� �� 쭬�ⓤ� � 信�젺�˚� � pⅶĦ���;                    � '
             db    ' �     /r - 쭬蟯�� �� 譽��⑨/쭬�ⓤ� � 信�젺�˚� � pⅶĦ���;             � '
             db    ' �     /n - 說汀�� 쭬蟯瞬 � 信�젺�˚� � pⅶĦ���;                       � '
             db    ' �     /u - 說汀� �昔｀젹с � 誓㎤ㄵ���.                                � '
             db    ' �  볚�젺�˚� � 誓㎤ㄵ�� 獸レぎ �黍 ��舒�� 쭬�信ぅ. 뗯‘� ㅰ膝�� か蹟   � '
             db    ' �  Œ� ⅲ� �恂呻飡˘� �留�㏂� ��琠ゥ��� 쩆���� Þ兒席졿Ŀ.             � '
             db    ' 훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠 '
 endif

 ifdef       Elisa
 @ElisaInfo  db    ' 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커 '
             db    ' �                                                                      � '
             db    ' �                 幡賽�  �      賽幡�  輻賽�   輻�                     � '
             db    ' �                 白複   �        �    霜�    �   �                    � '
             db    ' �                 �      �        �       霜  幡賽�                    � '
             db    ' �                 白複�  白複�  複白�  霜複�  �   �                    � '
             db    ' �                                                                      � '
             db    ' 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸 '
             db    '                                                                          '
             db    '                                                                          '
             db    ' �袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴� '
             db    ' �  ELISA - 將� ㄵМ�飡�졿Ŧ�췅� �昔｀젹쵟 �� ⓤ��レ㎜쥯�⑧ 歲飡�Л音   � '
             db    ' �  蓀ⅳ飡� MS DOS � BIOS ㄻ� IBM-貰¸α殊щ� ぎН溢收昔�. ELISA ¡�-   � '
             db    ' �  �昔�㎖�ㄸ� Дギㄸ�, ��譽� �� ˙⑨� 췅 �昔�㎖�ㄸ收レ��飡�  ぎН溢-   � '
             db    ' �  收��. 뤲� 쭬�信ぅ ⓤ��レ㎯荻碎 笹ⅳ莘蟯� か蹟�:                     � '
             db    ' �     /i - 信�젺�˘筍 �昔｀젹с � 誓㎤ㄵ�� (install);                  � '
             db    ' �     /u - 說汀� �昔｀젹с � 誓㎤ㄵ��� (uninstall).                    � '
             db    ' �  뗯‘� ㅰ膝�� か蹟 Œ� ⅲ� �恂呻飡˘� �留�㏂� ��琠ゥ��� 쩆���� Þ-   � '
             db    ' �  兒席졿Ŀ.                                                           � '
             db    ' �                                                                      � '
             db    ' �                                                                      � '
             db    ' 훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠 '
 endif

 @WriteInfo  proc
             push  ES

             ifdef Floppy
              lea   BP,@FloppyInfo
             endif

             ifdef Elisa             
              lea   BP,@ElisaInfo
             endif
             
             ifdef Locker
              lea   BP,@LockerInfo
             endif   

             ifdef Color
              lea   BP,@ColorInfo
             endif

             ifdef Defend
              lea   BP,@DefendInfo
             endif

             lea   SI,@Attr1
             mov   AX,@ScrBufSeg
             mov   ES,AX
             mov   DH,@TopRow
             mov   AL,160
             mul   DH
             mov   DI,AX
    @L1Draw: mov   DL,@LeftCol
             xor   BH,BH
             mov   BL,DL
             shl   BX,1
             add   BX,@PageOfs
    @L2Draw: mov   AH,DS:[SI]
             inc   SI
             mov   AL,DS:[BP]
             inc   BP
             mov   ES:[BX+DI],AX
             inc   BX
             inc   BX
             inc   DL
             cmp   DL,@RightCol
             jbe   @L2Draw
             add   DI,160
             inc   DH
             cmp   DH,@BotRow
             jbe   @L1Draw
             pop   ES
             ret
 @WriteInfo  endp
 
 @TestVideo  proc
             mov   AH,0Fh
             int   10h
             mov   @SaveRegime,AL
             cmp   AL,07h
             mov   AL,02h
             jne   @NotMDA

             mov   @ScrBufSeg,0B000h
             mov   AL,70h
             mov   CX,74*8
             lea   DI,@Attr1
             rep   stosb
             mov   AL,07h
             mov   CX,74*13
             lea   DI,@Attr2
             rep   stosb

   @NotMDA:  xor   AH,AH
             int   10h
             mov   CH,20h
             mov   AH,1
             int   10h

             push  ES
             xor   AX,AX
             mov   ES,AX
             mov   AX,ES:[44Eh]
             mov   @PageOfs,AX
             pop   ES
             
             mov   AX,1A00h
             int   10h
             cmp   AL,1Ah
             je    @EndTst
             dec   @VGAFlag

   @EndTst:  ret
 @TestVideo  endp

 @ReadPelReg proc
             mov   DX,3C7h
             xor   AL,AL
             cli
             out   DX,AL

             mov   CX,300h
             mov   DX,3C9h

   @NextPelR:in    AL,DX
             and   AL,3Fh
             stosb
             loop  @NextPelR

             sti
             ret
 @ReadPelReg endp

 @WritePelReg proc
             mov   DX,3C8h
             xor   AL,AL
             cli
             out   DX,AL

    @Vert:   mov   DX,3DAh
             in    AL,DX            
             and   AL,08h
             jz    @Vert

             mov   CX,300h
             mov   DX,3C9h

   @NextPelW:lodsb
             or    AL,AL
             jz    @OutPel
             add   AL,AH
             cmp   AL,0
             jg    @MaxPel
             mov   AL,0
             jmp   short @OutPel

   @MaxPel:  cmp   AL,3Fh
             jbe   @OutPel
             mov   AL,3Fh

   @OutPel:  out   DX,AL
             loop  @NextPelW

             sti
             ret
 @WritePelReg endp

 @BeepSound  proc
             mov     CX,90
             mov     DX,600
             mov     BX,600

             in      AL,61h
             and     AL,0FEh

    @L1Beep: push    CX
             or      AL,02h
             out     61h,AL

             mov     CX,DX
    @L2Beep: loop    @L2Beep
             sub     DX,5

             and     AL,0FDh
             out     61h,AL

             mov     CX,BX
    @L3Beep: loop    @L3Beep
             add     BX,5

             pop     CX
             loop    @L1Beep

             ret
 @BeepSound  endp

 @InfoAbout  proc
             cld
             mov   @MsgAddres,DX
             call  @TestVideo
             cmp   @VGAFlag,1
             jne   @NotVGA

             lea   DI,@PelRegMas
             call  @ReadPelReg
             mov   AH,-60
             lea   SI,@PelRegMas
             call  @WritePelReg

    @NotVGA: call  @WriteInfo
             cmp   @VGAFlag,1
             jne   @Key

             mov   AH,-60

    @Next:   inc   AH
             lea   SI,@PelRegMas
             call  @WritePelReg

             mov   CX,25000
    @Pausa:  loop  @Pausa

             cmp   AH,0
             jne   @Next

    @Key:    call  @BeepSound
             mov   AH,08h
             int   21h

             xor   AH,AH
             mov   AL,@SaveRegime
             int   10h
             ret 
 @InfoAbout  endp


def convert_ASCII(texte):
    res = []
    for i in texte:
        res.append(ord(i))
    return res

def convert_CHAR(ascii):
    res = ""
    for i in ascii:
        res += chr(i)
    return res

# info décalage de 5 = nskt

def chiffre_Cesar(texte, key):
    ascii_texte = convert_ASCII(texte)
    res = []

    for i in ascii_texte:
        if(i == 122):
            res.append(97)
        else:
            res.append(i + key)
    return convert_CHAR(res)

def dechiffre_Cesar(texte, key):
    ascii_texte = convert_ASCII(texte)
    res = []

    for i in ascii_texte:
        if(i == 97):
            res.append(122)
        else:
            res.append(i - key)
    return convert_CHAR(res)

test = "test"
chiffre = chiffre_Cesar(test, 1)
# print("Chiffré = " + chiffre)

dechiffre = dechiffre_Cesar(chiffre, 1)
# print("Déchiffré = " + dechiffre + "\n")

def frequence(texte):
    res = []
    compteur = {}

    # Fréquence des lettres.
    for i in texte:
        if i not in compteur:
            compteur[i] = 1
        else:
            compteur[i] += 1

    for i in compteur:
        res.append([convert_ASCII(i)[0], compteur[i]])

    return sorted(res)

texte = "\"Would it be of any use, now,\" thought Alice, \"to speak to this mouse? The rabbit is something quite out-of-the-way, no doubt, and so have I been, ever since I came down here, but that is no reason why the mouse should not be able to talk. I think I may as well try.\" So she began: \"oh Mouse, do you know how to get out of this pool? I am very tired of swimming about here, oh Mouse!\" The mouse looked at her rather inquisitively, and seemed to her to wink with one of its little eyes, but it said nothing. \"Perhaps it doesn't understand English,\" thought Alice; \"I daresay it's a French mouse, come over with William the Conqueror!\" (for, with all her knowledge of history, Alice had no very clear notion how long ago anything had happened,) so she began again: \"oÃ¹ est ma chatte?\" which was the first sentence in her French lesson-book. The mouse gave a sudden jump in the pool, and seemed to quiver with fright: \"oh, I beg your pardon!\" cried Alice hastily, afraid that she had hurt the poor animal's feelings, \"I quite forgot you didn't like cats!\" \"Not like cats!\" cried the mouse, in a shrill, passionate voice, \"would you like cats if you were me?\" \"Well, perhaps not,\" said Alice in a soothing tone, \"don't be angry about it. And yet I wish I could show you our cat Dinah: I think you'd take a fancy to cats if you could only see her. She is such a dear quiet thing,\" said Alice, half to herself, as she swam lazily about in the pool, \"she sits purring so nicely by the fire, licking her paws and washing her face: and she is such a nice soft thing to nurse, and she's such a capital one for catching mice - oh! I beg your pardon!\" cried poor Alice again, for this time the mouse was bristling all over, and she felt certain it must be really offended, \"have I offended you?\" \"Offended indeed!\" cried the mouse, who seemed to be positively trembling with rage, \"our family always hated cats! Nasty, low, vulgar things! Don't talk to me about them any more!\" \"I won't indeed!\" said Alice, in a great hurry to change the conversation, \"are you-are you-fond of-dogs?\" The mouse did not answer, so Alice went on eagerly: \"there is such a nice little dog near our house I should like to show you! A little bright-eyed terrier, you know, with oh! such long curly brown hair! And it'll fetch things when you throw them, and it'll sit up and beg for its dinner, and all sorts of things-I ca'n't remember half of them-and it belongs to a farmer, and he says it kills all the rats and-oh dear!\" cried Alice sadly, \"I'm afraid I've offended it again!\" for the mouse was swimming away from her as hard as it could go, and making quite a commotion in the pool as it went. So she called softly after it: \"mouse dear! Do come back again, and we won't talk about cats and dogs any more, if you don't like them!\" When the mouse heard this, it turned and swam slowly back to her: its face was quite pale (with passion, Alice thought), and it said in a trembling low voice \"let's get to the shore, and then I'll tell you my history, and you'll understand why it is I hate cats and dogs.\" It was high time to go, for the pool was getting quite full of birds and animals that had fallen into it. There was a Duck and a Dodo, a Lory and an Eaglet, and several other curious creatures. Alice led the way, and the whole party swam to the shore."
# print(frequence(texte))
# print("\n")

def cryptanalyse(cipher):
    dechiffrement = input("Tester avec qu'elle caractère ? ")

    freq = frequence(cipher)
    key = freq[0][0] - ord(dechiffrement)
    res = dechiffre_Cesar(cipher, key)

    return {'dechiffre': res, 'clef': key}

cipher = "[ol'yhiip{4ovsl'~lu{'z{yhpno{'vu'sprl'h'{|uuls'mvy'zvtl'~h\x803'huk'{olu'kpwwlk'z|kklus\x80'kv~u3'zv'z|kklus\x803'{oh{'Hspjl'ohk'uv{'h'tvtlu{'{v'{opur'hiv|{'z{vwwpun'olyzlsm3'ilmvyl'zol'mv|uk'olyzlsm'mhsspun'kv~u'~oh{'zlltlk'h'kllw'~lss5'Lp{oly'{ol'~lss'~hz'}ly\x80'kllw3'vy'zol'mlss'}ly\x80'zsv~s\x803'mvy'zol'ohk'wslu{\x80'vm'{ptl'hz'zol'~lu{'kv~u'{v'svvr'hiv|{'oly3'huk'{v'~vukly'~oh{'~v|sk'ohwwlu'ul\x7f{5'Mpyz{3'zol'{yplk'{v'svvr'kv~u'huk'thrl'v|{'~oh{'zol'~hz'jvtpun'{v3'i|{'p{'~hz'{vv'khyr'{v'zll'hu\x80{opunA'{olu3'zol'svvrlk'h{'{ol'zpklz'vm'{ol'~lss3'huk'uv{pjlk'{oh{'{ol\x80'~lyl'mpsslk'~p{o'j|wivhykz'huk'ivvr4zols}lzB'olyl'huk'{olyl'~lyl'thwz'huk'wpj{|ylz'o|un'vu'wlnz5'Zol'{vvr'h'qhy'kv~u'vmm'vul'vm'{ol'zols}lz'hz'zol'whzzlkA'p{'~hz'shilsslk')Vyhunl'Thythshkl3)'i|{'{v'oly'nylh{'kpzhwwvpu{tlu{'p{'~hz'ltw{\x80A'zol'kpk'uv{'sprl'{v'kyvw'{ol'qhy3'mvy'mlhy'vm'rpsspun'zvtlivk\x80'|uklyulh{o3'zv'thuhnlk'{v'w|{'p{'pu{v'vul'vm'{ol'j|wivhykz'hz'zol'mlss'whz{'p{5)^lss()'{ov|no{'Hspjl'{v'olyzlsm3')hm{ly'z|jo'h'mhss'hz'{opz3'P'zohss'{opur'uv{opun'vm'{|tispun'kv~u'z{hpyz('Ov~'iyh}l'{ol\x80.ss'hss'{opur'tl'h{'ovtl('^o\x803'P'~v|sku.{'zh\x80'hu\x80{opun'hiv|{'p{3'l}lu'pm'P'mlss'vmm'{ol'{vw'vm'{ol'ov|zl()'/~opjo'~hz'tvz{'sprls\x80'{y|l505'Kv~u3'kv~u3'kv~u5'^v|sk'{ol'mhss'ul}ly'jvtl'{v'hu'lukF')P'~vukly'ov~'thu\x80'tpslz'P.}l'mhsslu'i\x80'{opz'{ptlF)'zhpk'zol'hsv|k3')P't|z{'il'nl{{pun'zvtl~olyl'ulhy'{ol'jlu{yl'vm'{ol'lhy{o5'Sl{'tl'zllA'{oh{'~v|sk'il'mv|y'{ov|zhuk'tpslz'kv~u3'P'{opur\xe9\x87\x9b)'/mvy'\x80v|'zll'Hspjl'ohk'slhyu{'zl}lyhs'{opunz'vm'{opz'zvy{'pu'oly'slzzvuz'pu'{ol'zjovvsyvvt3'huk'{ov|no'{opz'~hz'uv{'h'}ly\x80'nvvk'vwwvy{|up{\x80'vm'zov~pun'vmm'oly'ruv~slknl3'hz'{olyl'~hz'uv'vul'{v'olhy'oly3'z{pss'p{'~hz'nvvk'wyhj{pjl'{v'zh\x80'p{'v}ly30')\x80lz3'{oh{.z'{ol'ypno{'kpz{hujl3'i|{'{olu'P'~vukly'~oh{'Svunp{|kl'vy'Sh{p{|kl4spul'zohss'P'il'puF)'/Hspjl'ohk'uv'pklh'~oh{'Svunp{|kl'~hz3'vy'Sh{p{|kl'lp{oly3'i|{'zol'{ov|no{'{ol\x80'~lyl'upjl'nyhuk'~vykz'{v'zh\x8050"
# print(cryptanalyse(cipher))



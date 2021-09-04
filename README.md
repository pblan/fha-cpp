# ToDo:
### 0x01
- [x] West Rose Cliff
- [x] Blue Canyon
- [x] Beverly Hollow
- [x] Sanborn Cliff
- [x] Pine Point

### 0x02
- [x] Baker River
- [x] Elkford
- [x] Harshire

### 0x03
- [ ] Ravencastle
- [ ] Stone Ridge
- [ ] Lucky Rock
- [ ] Meadow River
 
### 0x04
- [ ] Oakberg
- [ ] Brickgate
- [ ] Hicks Bluff
- [ ] Ashfield
- [ ] Sparrow Town
- [ ] Bakeropolis
 
### 0x05
- [ ] Copper View
- [ ] Kengate
- [ ] McAllen Spring
 
### 0x06
- [ ] Reeds Field
- [ ] South Birds Gale
- [ ] Green Mound
- [ ] Rose Pond
- [ ] Kenford
 
### 0x07
- [ ] Dover Town
- [ ] Heart Land
- [ ] Deerwoods

### 0x08
- [ ] Moore Rock
- [ ] Union Beach
- [ ] Peters Mines
 
### 0x09
- [ ] Eastbourne
- [ ] Openshaw
- [ ] Wintervale
- [ ] Banrockburn
- [ ] Clarcton
 
### 0x0a
- [ ] Roarport
- [ ] Kreley
- [ ] Yrouwood
- [ ] Pleim
 
### 0x0b
- [ ] Westwheat
- [ ] Coldwall
- [ ] Deepbutter
- [ ] Smoothrock
 
Command to check files for code conventions:
```bash
clear && clang-tidy -checks=*,cppcoreguidelines-*,google-*,llvm-*,-modernize-use-trailing-return-type,-llvmlibc-callee-namespace,-llvmlibc-implementation-in-namespace,-llvmlibc-restrict-system-libc-headers,-fuchsia-overloaded-operator,-*magic-numbers -header-filter=".*" uebungen/0x02/elkford.cpp <filename>
``` 

Kommentarformat:
```c++
/* Kommentierung
 *
 * (A)  Beschreibung
 *
 *      Siehe dazu auch:
 * <link>
 */
``` 
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
- [x] Ravencastle
- [x] Stone Ridge
- [x] Lucky Rock
- [x] Meadow River
 
### 0x04
- [x] Oakberg
- [x] Brickgate
- [x] Hicks Bluff
- [x] Ashfield
- [x] Sparrow Town
- [x] Bakeropolis
 
### 0x05
- [x] Copper View
- [x] Kengate
- [x] McAllen Spring
 
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
clear && clang-tidy -checks=*,cppcoreguidelines-*,google-*,llvm-*,-modernize-use-trailing-return-type,-llvmlibc-callee-namespace,-llvmlibc-implementation-in-namespace,-llvmlibc-restrict-system-libc-headers,-fuchsia-overloaded-operator,-*magic-numbers,-altera-unroll-loops,-fuchsia-default-arguments-calls -header-filter=".*" <filename>
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

# Using SSH Keys
If you encounter problems using SSH keys inside the development container, see the following guide:
https://code.visualstudio.com/docs/remote/containers#_using-ssh-keys

# IMPORTANT
- Manipulation in `0x05/mcallenspring.cpp` funktioniert nicht. Woran kann das liegen?
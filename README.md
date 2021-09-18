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
- [x] Reeds Field
- [x] South Birds Gale
- [x] Green Mound
- [x] Rose Pond
- [x] Kenford
 
### 0x07
- [x] Dover Town
- [x] Heart Land
- [x] Deerwoods

### 0x08
- [x] Moore Rock
- [x] Union Beach
- [x] Peters Mines
 
### 0x09
- [x] Eastbourne
- [x] Openshaw
- [x] Wintervale
- [x] Banrockburn
- [ ] Clarcton
 
### 0x0a
- [x] Roarport
- [x] Kreley
- [x] Yrouwood
- [x] Pleim
 
### 0x0b
- [ ] Westwheat
- [ ] Coldwall
- [ ] Deepbutter
- [ ] Smoothrock
 
Command to check files for code conventions:
```bash
clear && clang-tidy -checks=*,cppcoreguidelines-*,google-*,llvm-*,-modernize-use-trailing-return-type,-llvmlibc-callee-namespace,-llvmlibc-implementation-in-namespace,-llvmlibc-restrict-system-libc-headers,-fuchsia-overloaded-operator,-*magic-numbers,-altera-unroll-loops,-fuchsia-default-arguments-calls,-google-explicit-constructor,-hicpp-explicit-conversions,-cppcoreguidelines-explicit-virtual-functions,-hicpp-use-override,-modernize-use-override,-cppcoreguidelines-special-member-functions,-hicpp-special-member-functions,-misc-non-private-member-variables-in-classes,-altera-struct-pack-align -header-filter=".*" <filename>
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

# TBD
- Manipulation in `0x05/mcallenspring.cpp` funktioniert nicht. Compileroptimierungen?
- `using` statt `typedef`?
- Nutzen von `override`? (ab `0x08/moorerock.cpp`)
- Nutzen von `std::move` oder `std::string_view`?
- Musterlösung zu `0x09/clarcton`?
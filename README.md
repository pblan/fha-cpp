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
- [x] Westwheat
- [x] Coldwall
- [x] Deepbutter
- [x] Smoothrock
 
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
- [x] Manipulation in `0x05/mcallenspring.cpp` funktioniert nicht. Compileroptimierungen? -> Ja!
- [x] `using` statt `typedef`?
- [x] Nutzen von `override`? (ab `0x08/moorerock.cpp`) -> TBD mit Prof. Striegnitz
- [ ] Nutzen von `std::move` oder `std::string_view`?
- [x] Musterlösung zu `0x09/clarcton`? -> Nein.

# ToDo
- [x] Wo wird `typedef` eingeführt? -> `0x04`
- [x] `using` Alternative einführen (immer wenn `typedef` vorkommt)
- [ ] ab wann `using std`? (!)

# Liste aller Kommentierungen
## `0x01`
`beverlyhollow.cpp`
```c++
/* Kommentierung
 *
 * (A)  Für die Lesbarkeit sollte man auch für einzeilige Statement-Bodies die
 *      geschweiften Klammern nicht weglassen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/readability-braces-around-statements.html
 *
 *
 * (B)  Die Variable 'fi' hätte hier auch noch nicht deklariert werden können.
 *      In komplizierteren Fällen könnte es aber sein, dass das Nutzen
 *      einer nicht-deklarierten Variable zu undefiniertem Verhalten führt.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/cppcoreguidelines-init-variables.html
 *
 */
```

`bluecanyon.cpp`
```c++
/* Kommentierung
 *
 * (A)  Hier wäre es möglich, die Variablen 'b' und 'n' auch direkt in einer
 *      Zeile zu initialisieren.
 *      Für die Lesbarkeit ist es aber zu bevorzugen, die Variablendeklarationen
 *      zu isolieren.
 *
 *      Siehe dazu auch:
 https://clang.llvm.org/extra/clang-tidy/checks/readability-isolate-declaration.html
 */
```

`sanborncliff.cpp`
```c++
/* Kommentierung
 *
 * (A)  Es wird dazu geraten, statt C-style Arrays lieber std::array<> zu
 *      nutzen.
 *
 *      Siehe dazu auch:
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slcon1-prefer-using-stl-array-or-vector-instead-of-a-c-array

 * (B)  Analog sollte auch auf bound-safe Alternativen zurückgegriffen werden
 *      (std::vector<>, std::array<>).
 *
 *     Siehe dazu auch:
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rsl-bounds
 */
```

`westrosecliff.cpp` 
```c++
/* Kommentierung
 *
 * (A)  Variablennamen sollten zur Lesbarkeit stets aus mindestens drei Zeichen
 *      bestehen. Es gibt natürlich Namen, die generell verstanden werden, wie
 *      z.B. 'os' (Output Stream), 'st' (Stack), ...
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/readability-identifier-length.html
 */
``` 

## `0x02`

`harkshire.cpp` 
```c++
/* Kommentierung
 *
 * (A)  Per default wird ein std::string mit "" initialisiert.
 *      std::string delim = "";
 *      wuerde natuerlich funktionieren, wird aber nicht empfohlen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/fuchsia-overloaded-operator.html
 *
 * (B)  Generell sind ranged-based for-loops zu bevorzugen. Das spielt hier aber
 *      erstmal eine geringere Rolle.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-loop-convert.html
 */
``` 

## `0x03`
`luckyrock.cpp` 
```c++
/* Kommentierung
 *
 * (A)  Mit der Einführung von `std::move` ist es (oft) effizienter ein Argument
 * per Value zu übergeben, statt einer const-reference, und dann zu kopieren.
 * Bei std::string ist es auf jeden Fall zu bevorzugen, spielt hier in der
 * Vorlesung aber eine geringere Rolle.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-pass-by-value.html
 */
``` 

`meadorwiver.cpp` 
```c++
/* Kommentierung
 *
 * (A)  Data Members sollten in der Regel als private deklariert werden. Für den
 * Zugriff sollten Memberfunktionen genutzt werden.
 * Zum jetzigen Zeitpunkt ist das aber nötig, da der Ausgabeoperator auf coeffs
 * zugreifen muss. Mehr dazu später bei dem Keyword `friend`.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/misc-non-private-member-variables-in-classes.html
 *
 * (B)  dtors, move-ctors, move-assignment Operatoren, main(), swap(),
 * Funktionen mit throw() oder noexcept sollten keine Exceptions werfen. Das
 * könnte zu undefiniertem Verhalten führen; ein gutes Beispiel wäre eine
 * Exception in einem dtor, wodurch Objekte potentiell nicht richtig abgeräumt
 * werden können.
 * Wenn man natürlich gründlich alle Exceptions fängt, braucht man sich
 * diesbezüglich natürlich keine Sorgen machen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/bugprone-exception-escape.html
 */
``` 

`ravencastle.cpp` 
```c++
/* Kommentierung
 *
 * (A)  Natürlich würde ein ctor der Form `fraction() : num_{}, denom_{} {};`
 * das gleiche tun, wie der explizite default-ctor.
 * Es gibt allerdings einige (hier nicht weiter behandelte) Unterschiede.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-default-member-init.html
 * https://stackoverflow.com/questions/20828907/the-new-syntax-default-in-c11
 *
 * (B)  Wenn eine Klasse einen nutzerdefinierten dtor, copy-ctor oder
 * copy-operator (später) benötigt, ist es in den allermeisten Fällen sinnvoll
 * alle drei zu definieren.
 *
 *      Siehe dazu auch:
 * https://en.cppreference.com/w/cpp/language/rule_of_three
 *
 * (C)  Mehrere Parameter des gleichen Typs können beim Funktionsaufruf leicht
 * vertauscht werden. Alternativ sollte man type-safe Konstrukte nutzen, wie
 * z.B. typedefs oder structs.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/bugprone-easily-swappable-parameters.html
 */
``` 

`stoneridge.cpp`
```c++
/* Kommentierung (analog zu Ravencastle)
 *
 * (A)  Natürlich würde ein ctor der Form `fraction() : num_{}, denom_{} {};`
 * das gleiche tun, wie der explizite default-ctor.
 * Es gibt allerdings einige (hier nicht weiter behandelte) Unterschiede.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-default-member-init.html
 * https://stackoverflow.com/questions/20828907/the-new-syntax-default-in-c11
 *
 * (B)  Wenn eine Klasse einen nutzerdefinierten dtor, copy-ctor oder
 * copy-operator (später) benötigt, ist es in den allermeisten Fällen sinnvoll
 * alle drei zu definieren.
 *
 *      Siehe dazu auch:
 * https://en.cppreference.com/w/cpp/language/rule_of_three
 *
 * (C)  Mehrere Parameter des gleichen Typs können beim Funktionsaufruf leicht
 * vertauscht werden. Alternativ sollte man type-safe Konstrukte nutzen, wie
 * z.B. typedefs oder structs.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/bugprone-easily-swappable-parameters.html
 */
```

## `0x04`
`brickgate.cpp`
```c++
/* Kommentierung
 *
 * (A)  Seit C++11 wird es empfohlen, statt `typedef` das Keyword `using` zu
 * nutzen. Eine "alias-declaration" mit `using` würde in diesem Fall so
 * aussehen: `using it_type = std::vector<int>::const_iterator;` Neben der
 * verbesserten Lesbarkeit hat die Alternative mit `using` auch Vorteile beim
 * Nutzen von Alias Templates.
 *
 *      Siehe dazu auch:
 * https://www.nextptr.com/tutorial/ta1193988140/how-cplusplus-using-or-aliasdeclaration-is-better-than-typedef
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-using.html
 *
 * (B)  Auch hier wäre in der Praxis wieder eine range-based for-Schleife zu
 * bevorzugen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-loop-convert.html
 */
```

## `0x05`

`mcallenspring.cpp`
```c++
/* Kommentierung
 *
 * (A)  Der +-Operator sorgt in diesem Beispiel dafür, dass der eigentliche
 * char-Wert als int interpretiert wird.
 *
 *      Siehe dazu auch:
 * https://docs.microsoft.com/en-us/cpp/cpp/unary-plus-and-negation-operators-plus-and?view=msvc-160
 */
```

## `0x06`

`greenmound.cpp`
```c++
/* Kommentierung
 *
 * (A)  In der Regel sollten globale Variablen nicht non-const sein.
 *
 *      Siehe dazu auch:
 * https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Ri-global
 *
 * (B)  Es ist wichtig, den richtigen Deallocator für die jeweilige Operation zu
 *      nutzen: malloc / free, new / delete, new[] / delete[]
 *
 *      Siehe dazu auch:
 * https://stackoverflow.com/a/24405905/9055591
 */
```

`kenford.cpp`
```c++
/* Kommentierung
 *
 * (A)  Der Compiler kann bei einem Methodenaufruf eine implizite Konvertierung
 *      durchführen, um die Parameter anzupassen.
 *      Das bedeutet, dass der Compiler einen Konstruktor (mit einem einzigen
 *      Parameter) aufrufen kann, um den richtigen Typen für den Parameter zu
 *      erzeugen. Das sorgt unter Umständen dazu führen, dass Bugs schwieriger
 *      zu erkennen sind, insbesondere, wenn der Parametertyp nicht primitv ist.
 *
 *      Empfohlen wird daher das Keyword `explicit` bei Konstruktoren mit einem
 *      Parameter, also hier entsprechend:
 *      `explicit node(const value_type &value) : value{value} {}`
 *
 *      Siehe dazu auch:
 * https://google.github.io/styleguide/cppguide.html#Explicit_Constructors
 * https://clang.llvm.org/extra/clang-tidy/checks/google-explicit-constructor.html
 */
```

`reedsfield.cpp`
```c++
/* Kommentierung
 *
 * (A)  Hier wird der char-pointer in einen void-pointer umgewandelt.
 *      Das sorgt dafür, dass der Pointer nicht weiter 'interpretiert' wird und
 *      letztendlich der Wert, also effektiv die Speicheradresse auf die der
 *      Pointer zeigt, ausgegeben wird.
 *
 *      Siehe dazu auch:
 * https://www.learncpp.com/cpp-tutorial/void-pointers/
 *
 * (B)  C-style Casts werden generell nicht empfohlen.
 *      Besser wäre hier z.B.:
 *      `static_cast<int>(*ptr)`
 *
 *      Siehe dazu auch:
 * https://google.github.io/styleguide/cppguide.html#Casting
 */
```

`rosepond.cpp`
```c++
/* Kommentierung
 *
 * (A)  Das Standardverhalten von auto ist, dass eine Kopie erzeugt wird.
 *      In diesem Ausgabeoperator wäre eine Kopie nicht sinnvoll, insbesondere
 *      durch std::unique_ptr, daher wählen wir hier 'const auto* it'.
 *
 *      Siehe dazu auch:
 * https://llvm.org/docs/CodingStandards.html#beware-unnecessary-copies-with-auto
 */
```

## `0x07`
`dovertown.cpp`
```c++
/* Kommentierung
 *
 * (A)  Wir wollen hier lediglich values lesen - nicht verändern oder kopieren.
 *      Merke:
 *      `auto x`:           wenn mit Kopien gearbeitet werden soll.
 *      `auto &x`:          wenn mit dem Original gearbeitet werden soll und es
 *                          potentiell verändert wird.
 *      `const auto &x`:    wenn mit dem Original gearbeitet werden soll und es
 *                          nicht verändert wird.
 */
```


## `0x08`
`moorerock.cpp`
```c++
/* Kommentierung
 *
 * (A)  Sei C++11 existiert das 'override' Keyword. Dieses sollte dann genutzt
 *      werden, wenn eine erbende Klasse eine virtuelle Funktion der Basisklasse
 *      überschreibt.
 *      Neben der geförderten Lesbarkeit kann der Compiler mit dem Keyword auch
 *      feststellen, ob die Methode korrekt überschrieben wurde, oder ob sich
 *      potentiell die Signatur der Funktion in der Basisklasse verändert hat.
 *      Im Beispiel würde die Signatur in der erbenden Klasse dann so aussehen:
 *      'void draw() override { ... }''
 *
 *      Siehe dazu auch:
 * https://en.cppreference.com/w/cpp/language/override
 */
```
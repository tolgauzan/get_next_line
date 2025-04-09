
# GetNextLine

Bu proje, bir dosya tanımlayıcısından her seferinde bir satır okuyan çok kullanışlı bir işlevi kodlamakla ilgilidir. Gelecekteki projeler için [Libft](https://github.com/tolgauzan/libft) koleksiyonuna eklenmelidir.

**Grade** : 125/100 \

## İçerik

| **Program Adı**       | get_next_line                             |
|-----------------------|-------------------------------------------|
| **Prototip**           | `char *get_next_line(int fd);`            |
| **Teslim Edilecek Dosyalar** | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| **Parametreler**       | `fd`: Okunacak dosya tanımlayıcısı       |
| **Dönüş Değerleri**    | Okunan bir satır (string) veya `NULL` (okunacak başka şey yoksa veya hata oluşursa) |
| **Harici Fonksiyonlar**| `read`, `malloc`, `free`                  |
| **Açıklama**           | Dosya tanımlayıcıdan okunan satırı döndüren bir fonksiyon yazın |

</br>
İşlev, bir dosya tanımlayıcısından okunan bir satır döndürür. Ardışık çağrılar ardışık satırları teker teker döndürür. Satır, dosyanın sonuna ulaşıldığı ve bir `\n` karakteriyle bitmediği durumlar haricinde, fonksiyondan dönen değer sonlandırıcı bir `\n` karakteriyle biten bir karakter dizisidir.

### Zorunlu Bölüm
- `get_next_line` fonksiyonunun bir dosya tanımlayıcısını okuyarak her çağrıda bir satır döndürmesi gereklidir.
- `BUFFER_SIZE` parametresi ile uyumlu çalışmalı ve hata durumlarını doğru şekilde ele almalıdır.

### Bonus Bölüm
- `get_next_line`, birden fazla dosya tanımlayıcısını (multi-file descriptor) aynı anda yönetebilmelidir.
- Her dosya tanımlayıcısı bağımsız bir şekilde ele alınmalı ve işlemler bir diğerini etkilememelidir.
---
### Kullanım

Kodunuza uygun başlıklardan birini ekleyin:
```c
#include "get_next_line.h"
#include "get_next_line_bonus.h"
```

Uygun dosyaları kullanarak main.c kodunuzu derleyin:
```bash
[ gcc | clang | cc ] -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

Bonus versiyonunu kullanmak için:
```bash
[ gcc | clang | cc ] -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

***Kodunuzu derlerken **BUFFER_SIZE** makrosunu değiştirebilirsiniz. Arabellek boyutu farklı değerlerle çalışabilmelidir:***

Uygun dosyaları kullanarak main.c kodunuzu derleyin:
```bash
[ gcc | clang | cc ] -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

Bonus versiyonunu kullanmak için:
```bash
[ gcc | clang | cc ] -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

Örnek `main.c` :
```c
#include "get_next_line.h"
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("Satır: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

Bonus bölümde fonksiyonumuz birden fazla ***File Descriptor*** ile çalışabilir 

---
### Test
Bunlar, tamamlayıcı testler yapmak için üçüncü taraf test cihazlarıdır, bunları kendi sorumluluğunuzda kullanın:
- @xicodomingues [francinette](https://github.com/xicodomingues/francinette)

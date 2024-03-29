# ProLab2
Bu projenin amacı, çeşitli sensörler kullanarak mikrodenetleyici tabanlı bir oyun makinesi
geliştirmektir.
Oyun, uzay ortamında çeşitli meteor ve uzay çöplerinden kaçmaya çalışan bir uzay gemisini ele
almaktadır. Uzay gemisi yalnızca sağa, sola hareket ederek objelerden kaçabilmekte ve yeterli
mühimmata sahip olabilirse objeleri yok edebilmektedir. Oyun ortamı; genişliği 8, uzunluğu 16 olan
bir matristen oluşmaktadır. Oled ekran kullanılarak arayüz gösterilecek ve matrislerden oluşan bu uzay
ortamı kullanıcılara sunulacaktır. Oyun; matriste kullanıcının kontrol ettiği karakter her zaman 1.satırda
kalacak şekilde, matrisin en son bölgesinde rastgele oluşturulan engel objeleri ise her saniye 1 kare
aşağıya inecek şekilde tasarlanmalıdır. Böylece platform aşağıya doğru kayacak şekilde tasarlanmış
olacaktır. Kullanılacak araç dışında, rastgele şekilde oluşturulacak karakterler; engel karakteri (meteor
veya uzay çöpü), ödül puanı (bu alındığında kullanıcı ekstra 1 hak kazanır, yedek can), silah (bununla
kullanıcının yönettiği karakter önüne doğru bir obje fırlatır, ilk çarptığı engel karakterinin canını 1
azaltır), dokunulmazlık (alındığı zaman 3 saniye boyunca engele çarpsa bile oyuncunun hakkı gitmez)
oluşturulur. Her oluşturulacak satıra (8 kareye) rastgele objeler, 1 adet boşluk bırakılacak şekilde
yerleştirilmelidir. Uzay aracı bu boşluktan hareketine devam edebilecektir. Rastgele oluşturulan
nesnelerden her 14 engelde bir kere, 1 can ve 1 silah hakkı da eklenmelidir. Bu nesnelerin dizilimleri
rastgele oluşturulmalıdır. Kullanıcının engelleri yok edebilmesi için; meteor ise 2 kere atış yapması,
uzay çöpü ise 1 kere atış yapması gerekmektedir.
Rastgele nesneler Şekil 1’de gösterilmiş olan A bölgesinden oluşmaya başlamaktadır ve her saniye
aşağıya doğru bir kare ilerlemektedir. Her saniyede yeni rastgele nesneler oluşturulmaktadır. Uzay aracı
ise yalnızca B bölgesinde bulunacak ve sağa, sola hareket edebilecektir.(Şekilde B ilk satırı, A son satırı
göstermektedir.

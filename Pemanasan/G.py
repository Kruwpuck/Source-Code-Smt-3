def process_number(N, K):
    N_str = str(N)  # Ubah N menjadi string
    unique_digits = []
    seen = set()
    
    # Ambil K digit unik pertama
    for digit in N_str:
        if digit not in seen:
            seen.add(digit)
            unique_digits.append(digit)
        if len(unique_digits) == K:
            break
    
    # Tentukan digit terkecil dan terbesar dari K digit unik yang ditemukan
    unique_digits = list(map(int, unique_digits))  # Ubah ke integer untuk perbandingan
    min_digit = min(unique_digits)
    last_unique_digit = unique_digits[-1]
    
    # Cari posisi terakhir dari digit unik yang sudah ditemukan
    last_unique_position = N_str.rfind(str(last_unique_digit))
    
    # Periksa apakah digit setelah digit unik terakhir lebih besar daripada digit unik
    condition_met = False
    if last_unique_position < len(N_str) - 1 and int(N_str[last_unique_position + 1]) > max(unique_digits):
        condition_met = True
        # Jika kondisi 1 terpenuhi, tambahkan 1 pada digit terakhir dari `unix`
        unique_digits[-1] += 1
        last_unique_digit = unique_digits[-1]
    
    # Tentukan digit yang akan digunakan untuk mengganti angka setelah posisi terakhir digit unik
    if condition_met:
        replace_digit = min_digit
        # Ubah sisa digit setelah posisi terakhir menjadi digit terkecil
        result = list(N_str)  # Ubah ke list untuk manipulasi mudah
        for i in range(last_unique_position + 1, len(result)):
            result[i] = str(replace_digit)
        final_number = int(''.join(result))
    else:
        # Cek jika menambahkan 1 pada digit terakhir tetap berada dalam `unix`
        if last_unique_digit + 1 in unique_digits:
            # Jika kondisi 2, ganti digit terakhir menjadi angka terkecil dan ubah sisanya
            result = list(N_str)
            result[last_unique_position] = str(min_digit)
            for i in range(last_unique_position + 1, len(result)):
                result[i] = str(min_digit)
            final_number = int(''.join(result))
        else:
            # Jika kondisi 3, ganti digit setelah digit unik terakhir menjadi angka terkecil
            result = list(N_str)
            for i in range(last_unique_position + 1, len(result)):
                result[i] = str(min_digit)
            final_number = int(''.join(result))

    return final_number

# Input N dan K
N, K = map(int, input().split())

# Proses angka dan tampilkan hasil
result = process_number(N, K)

# Tampilkan hasil perbedaan antara hasil baru dan N
print(result)

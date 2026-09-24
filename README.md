<h3 align="center">Git Deployment – Làm việc nhóm trong GitHub - Git Trick</h3>

<details>
<summary><b>1. Git Deployment</b></summary>

Chuẩn bị một đoạn code mẫu: <https://drive.google.com/drive/folders/1OiO-k-1bLbI6Ag1ySMGKIG_1ek_O0AJU?usp=sharing>

1. ```git init:``` Khởi tạo Git cho thư mục dự án.
2. ```.gitignore:``` là một file cấu hình dùng để khai báo cho Git biết những file hoặc thư mục nào không cần theo dõi và không đẩy lên repo. 

>**Ví dụ:**
>
>- Loại bỏ file “.DS\_Store”:
>
>  ```.DS\_Store```
>
>- Loại bỏ folder “.firebase/”:
>
>  ```.firebase/```
>
>- Loại bỏ theo đuôi file “.log”:
>
>  ```\*.log```
>
>**Lưu ý:**
>
>- ```.gitignore``` chỉ chặn được file chưa từng được thêm. File đã commit rồi vẫn nằm trong lịch sử, muốn gỡ  thì dùng lệnh: ```git rm –cached $tên file$```. Ví dụ: git rm --cached firebase.json.
>- Tham khảo cách sử dụng: <https://gitignore.io/>

3. ```git add <file> || git add . || git add \*:``` Đưa các thay đổi vào Staging Area.

>**Trong đó:**
>
>- ```git add <file>``` là thêm 1 file chỉ định, nhưng vẫn chịu sự theo dõi của ```.gitignore```. Nếu vẫn muốn >add thì dùng câu lệnh ```git add -f <file>```
>- ```git add .``` là thêm các file/folder mà git đang quản lý. Chịu theo dõi của ```.gitignore```.
>- ```git add \*``` là thêm các file/folder, không chịu sự theo dõi của ```.gitignore```.
4. ```git status:``` Kiểm tra trạng thái hiện tại của các file.
5. ```git commit -m “$message$”:``` Lưu trạng thái các file hiện tại thành lịch sử.
6. ```git branch -M main || git branch -M {tên gì đó}:``` Đổi tên nhánh hiện tại ở máy local thành main hoặc {tên gì đó}.
7. ```git remote add origin ${đường dẫn}$:``` Thêm liên kết đến kho chứa trên GitHub với biệt danh origin.
8. ```git push -u origin main || git push origin main || git push {biet danh} {ten nhanh}:``` Đẩy toàn bộ mã nguồn từ nhánh main cục bộ lên nhánh main trong origin. Bạn có thể kiểm tra những file nào được đẩy lên qua câu lệnh ```git status``` mà tôi đã giới thiệu.
9. ```git log ||git log –oneline || git log --oneline -10 || git log --oneline --graph –all || git commit --amend:``` Xem lịch sử đã commit.

>**Trong đó:** ```git commit –amend``` cho phép sửa lại tên commit vừa tạo gần nhất nếu lỡ viết sai
><p align="center">
><img width="756" height="386" alt="image" src="https://github.com/user-attachments/assets/a1134cbb-51a5-4723-bfd8-fa6d3e4f8f38" />
></p>
><p align="center">
><img width="833" height="206" alt="image" src="https://github.com/user-attachments/assets/7ed01e49-d4a5-4dca-9d74-2d2a1128260d" />
></p>

10. Cấu trúc một Commit Message chuẩn: ```<type>(<scope>): <mô tả ngắn>```

>- ```type:``` Loại công việc vừa làm. Các giá trị thường gặp:
>- ```feat:``` Thêm tính năng mới (Feature).
>- ```fix:``` Sửa lỗi (Bug fix).
>- ```docs:``` Sửa đổi tài liệu, comment.
>- ```chore:``` Các công việc lặt vặt, không chỉnh sửa logic code.
>- ```refactor:``` Sửa cấu trúc code cho tối ưu mà không đổi tính năng.
>- ```test:``` Thêm hoặc sửa code kiểm thử.
>- ```style:``` Sửa định dạng.
>- ```perf:``` Cải thiện hiệu năng.
>- ```scope:``` Chỉ rõ phần code bị tác động.
<p align="center">
<img width="1068" height="672" alt="image" src="https://github.com/user-attachments/assets/beacfba5-f96a-4867-a0ea-9d0a5859a9b6" />
</p>

11. Sửa sai với ```status/ diff/ restore, git status --porcelain```

**Problem:**

- Nếu sửa nhầm file, hoặc git add nhầm file chưa muốn commit.

**Approach:**

- Học cách đọc output của git status –porcelain để biết chính xác đang ở trạng thái nào

```git status --porcelain:```

Chúng ta hình dung, một dự án khi code sẽ có các quá trình để push lên github:

```Working Tree ---> git add ---> Staging Area ---> git commit ---> Repository```

- Đọc 2 ký tự đầu mỗi dòng của –porcelain
>- ??: file mới, Git chưa biết tới
>- M` `: file đã sửa và đã add
>- ` `M: đã sửa nhưng chưa add
>- MM: đã add rồi nhưng vẫn sửa tiếp, cần add lại

**Solution:**

1. Sửa hỏng code (chưa git add)
- Xem những gì đã sửa: ```git diff (Không bắt buộc)```
- Quy về lại commit cũ: ```git restore <tên\_file>```
<p align="center">
<img width="1068" height="346" alt="image" src="https://github.com/user-attachments/assets/41effd2e-dacb-412c-a69e-c10a66c5bf2c" />
</p>
<p align="center">
<img width="1068" height="74" alt="image" src="https://github.com/user-attachments/assets/4db1a09c-0ff3-4363-93af-5740f4c3ef88" />
</p>
-	Hoặc chuyển về commit cũ: git reset + mã commit, hoặc git reset --soft + mã commit (nếu vẫn giữ commit cũ)
<img width="1068" height="1063" alt="image" src="https://github.com/user-attachments/assets/23cf4815-1fea-48d2-9686-d5e3e4bee20e" />
-	Chuyển local về commit 7e0d3a2: 
Tạo folder mới -> git clone -> chuyển về folder clone -> git checkout -b + mã commit (-b là viết tắt của branch)
<img width="1068" height="572" alt="image" src="https://github.com/user-attachments/assets/65c9a055-ead2-44ed-a426-909838575939" />
<img width="1068" height="494" alt="image" src="https://github.com/user-attachments/assets/bcdace91-e483-4db9-a231-9058e44326c4" />

2. ```Git add``` nhầm
- Xem Staging đang có gì: ```git diff --staged``` (Không bắt buộc)
- Bỏ ra khỏi: ```git restore --staged <tên\_file>```


12. Nhánh trong GitHub:
- ```git branch ${tên nhánh mới}$:``` Tạo nhánh mới
- ```git switch ${tên nhánh}$:``` Chuyển sang nhánh ```${tên nhánh}$```
- ```git switch -c ${tên nhánh}$ ${nhánh cũ}$:``` Tạo nhánh mới và chuyển ngay sang nhánh mới từ nhánh cũ
**Lưu ý: Các bạn nên tìm hiểu về** ```git checkout``` **nữa**.
- Chuyển vào nhánh chính, sau đó gộp code với nhánh mới khi hoàn thành các tính năng:

  ```git switch main```

  ```git merge ${tên nhánh mới}$```

**Lưu ý:**

- Nếu cùng 1 file mà nội dung của 2 nhánh khác nhau thì github sẽ hiện ra thông báo cần xử lý
- Nếu ưu tiên nhánh mới hơn thì dùng câu lệnh: ```git merge ${tên nhánh mới}$ -> git merge -X theirs ${tên nhánh mới}$```
- Nếu bạn muốn lấy file/ folder nào đó từ nhánh mới (Đảm bảo rằng bạn đang đứng ở nhánh mong muốn): ```git restore --source=${tên nhánh mới}$ file1.js file2.css thu\_muc\_moi/```
<p align="center">
<img width="600" alt="image" src="https://github.com/user-attachments/assets/cd19a34c-2fac-41a4-9e0f-e1a6ea38a8fe" />
</p>
<p align="center">
<img width="600" alt="image" src="https://github.com/user-attachments/assets/7412835f-241b-4446-a68b-f52a8d2ffe1f" />

</p>
<p align="center">
<img width="600" alt="image" src="https://github.com/user-attachments/assets/11afca67-55f1-4cbc-be59-e83be0f01b36" />

</p>

13. ```git merge``` và ```git rebase``` từ nhánh A vào nhánh B, phân biệt và  sử dụng hiệu quả?
<img width="700" height="684" alt="image" src="https://github.com/user-attachments/assets/97a71dc2-d90a-43ec-980c-581129e5d273" />
**Nhìn vào hình minh họa merge vs rebase:**
**Merge:**
Khi chúng ta hoặc team phát triển một tính năng nào đó mới, chúng ta thường hay có xu hướng tạo ra branch mới, khi merge code bằng git merge thì sẽ tạo ra một merge commit khi ta gộp vào nhánh chính.
------> Khi merge như vậy thì lịch sử commit của nhánh main vẫn được đảm bảo.
Về cơ bản, hiểu đơn giản là merge từ nhánh feature vào nhánh main. Nhánh feature vẫn còn đó, nhánh main sẽ nhận được commit mới từ nhánh feature.
**Rebase:**
Tương tự merge, chúng ta cũng có nhánh main và nhánh feature để phát triển sản phẩm/ tính năng mới. Thay vì chúng ta sử dụng git merge chúng ta sẽ sử dụng git rebase, nó sẽ di chuyển các file từ nhánh feature vào nhánh main mà không tạo ra commit mới.
------> Nhánh feature sẽ không còn lịch sử commit nữa, tại vì tất cả chúng đều đã di chuyển sang nhánh main.
**Tóm lại:**
- ```git merge``` khi chúng ta muốn giữ nguyên commit của nhóm feature và nhánh main. Thể hiện tính rõ ràng và hợp nhất giữa các commit.
- ```git rebase:``` Thích hợp khi chúng ta muốn các commit rõ ràng và gọn gàng hơn, do chúng nhận được các commit từ nhánh feature.
**Quy tắc xuyên suốt:** Luôn pull trước khi merge+push
**Thực chiến git merge:**
<img width="1068" height="483" alt="image" src="https://github.com/user-attachments/assets/8907d7ee-f9b1-4620-84cd-42e293359d56" />
Giả sử ta thêm nhánh vidu_merge vào nhánh caulenh1-9
Ở nhánh vidu_merge có file mới là nenday.cpp và sửa đổi file index.html, ta sẽ làm như nào để hợp nhất code từ vidu_merge vào nhánh caulenh1-9?
<img width="1068" height="408" alt="image" src="https://github.com/user-attachments/assets/5fabcf70-d212-433c-896d-43d14020da33" />
**Conflict giữa 2 file:**
<img width="1068" height="144" alt="image" src="https://github.com/user-attachments/assets/a3108668-3475-4e78-8f01-0184c9254a9a" />
**Question:** Các bạn hãy tìm hiểu xem ```--allow-unrelated-histories --no-edit``` mà mình dùng là gì nhé, vì sao phải dùng?
**Hint:**
<img width="241" height="252" alt="image" src="https://github.com/user-attachments/assets/7602d5a0-b3e4-4d29-b5c0-9a04d30c1892" />

```--no-edit``` -> không mở trình chỉnh sửa
<img width="1068" height="673" alt="image" src="https://github.com/user-attachments/assets/d3e4276e-2f6c-4d58-851f-f6daa44a5b53" />
<img width="1068" height="141" alt="image" src="https://github.com/user-attachments/assets/7f43f127-ca46-4eb3-b677-8fee7cfbf47f" />
**Thực chiến git rebase:**
Tạo nhánh vidu_rebase có cùng lịch sử commit với nhánh mới:
<img width="1068" height="96" alt="image" src="https://github.com/user-attachments/assets/598c78e9-20f1-4654-93f2-116cc0a0ad7d" />
<img width="1068" height="495" alt="image" src="https://github.com/user-attachments/assets/8b083743-e873-494f-813c-ff472f2ec224" />
Giả sử, ta sẽ tạo 1 file mới và sửa 1 file nào đó:
**Thực hiện rebase:**
<img width="1068" height="509" alt="image" src="https://github.com/user-attachments/assets/08ad0836-1c2f-4fad-9cfb-e88baabfd049" />
Thực hiện pull: Kéo code về và vẫn giữ được lịch sử commit
<img width="1068" height="1219" alt="image" src="https://github.com/user-attachments/assets/590eff3e-1213-449c-a7d2-277e65b5249b" />
<img width="1068" height="675" alt="image" src="https://github.com/user-attachments/assets/a085d9cd-b263-4633-a47e-e11ba9b6dac3" />
<img width="1068" height="453" alt="image" src="https://github.com/user-attachments/assets/95cfef26-086a-4853-9ad8-e37f2bbbe5d6" />
Về cơ bản, git rebase lấy các commit của vidu_rebase đặt sau các commit của nhanh_moi
<img width="1068" height="294" alt="image" src="https://github.com/user-attachments/assets/89817c8d-b6ae-4458-bff9-fffa439697b8" />

</details>

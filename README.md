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
8. ```git push -u origin main:``` Đẩy toàn bộ mã nguồn từ nhánh main cục bộ lên nhánh main trong origin. Bạn có thể kiểm tra những file nào được đẩy lên qua câu lệnh ```git status``` mà tôi đã giới thiệu.
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

2. ```Git add``` nhầm
- Xem Staging đang có gì: ```git diff --staged``` (Không bắt buộc)
- Bỏ ra khỏi: ```git restore --staged <tên\_file>```


12. Nhánh trong GitHub:
- ```git branch ${tên nhánh mới}$:``` Tạo nhánh mới
- ```git switch ${tên nhánh}$:``` Chuyển sang nhánh ```${tên nhánh}$```
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
</details>

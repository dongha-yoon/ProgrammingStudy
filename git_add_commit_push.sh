date=$(date "+%m%d")

git add .
git commit -m "${date}"
git push origin master

date=$(date "+%m%d")
echo "${date}"

git add .
git commit -m "${date}"
git push origin master

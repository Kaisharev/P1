:: ===============================================
::  Date:                           08. 11. 2024.
::  Author:                     Slađan Stevanović
:: ===============================================

@echo off

chcp 65001 > nul

echo.
set /p "name_and_surname=Unesite Vaše ime i prezime: "
set /p "email=Unesite Vaš email: "

git config --local user.name "%name_and_surname%"
git config --local user.email "%email%"
git config --local core.sshCommand "ssh -i ../ssh/key"

if exist ssh exit /b

:password_input
echo.
for /f "usebackq delims=" %%p in (`powershell -Command "$password = Read-Host -AsSecureString 'Unesite lozinku Vašeg SSH ključa'; [Runtime.InteropServices.Marshal]::PtrToStringAuto([Runtime.InteropServices.Marshal]::SecureStringToBSTR($password))"`) do set "password=%%p"
for /f "usebackq delims=" %%p in (`powershell -Command "$password = Read-Host -AsSecureString 'Ponovo unesite lozinku Vašeg SSH ključa'; [Runtime.InteropServices.Marshal]::PtrToStringAuto([Runtime.InteropServices.Marshal]::SecureStringToBSTR($password))"`) do set "repeated_password=%%p"

if not "%password%"=="%repeated_password%" (
    echo.
    echo ===============================================
    echo  Lozinke se ne podudaraju! Pokušajte ponovo...
    echo ===============================================

    goto :password_input
)

mkdir ssh
cd ssh
ssh-keygen -t rsa -b 2048 -f key -N "%password%" > nul
clip < key.pub
cd ..

echo.
echo ===================================================================
echo  Vaš javni ključ, koji dodajete u BitBucket, je kopiran!
echo  Nakon što dodate ključ, pritisnite bilo koju tipku za nastavak...
echo ===================================================================
pause > nul

echo.
echo ================================================================================
echo  Odlično! Kada Vas BitBucket pita za lozinku, unesite lozinku Vašeg SSH ključa.
echo ================================================================================

echo.
set "repository_name=P1
mkdir %repository_name%
cd %repository_name%
git init > nul
git config --local user.name "%name_and_surname%"
git config --local user.email "%email%"
git config --local core.sshCommand "ssh -i ../ssh/key"
git remote add origin https://github.com/Kaisharev/%repository_name%.git
git pull origin main
cd ..

echo.
echo ========================================================
echo  Vaš repozitorijum je kloniran i spreman za korištenje!
echo ========================================================
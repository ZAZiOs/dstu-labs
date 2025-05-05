# Устанавливаем UTF-8 для ввода/вывода консоли
[Console]::InputEncoding = [Console]::OutputEncoding = [System.Text.Encoding]::UTF8

$outputDir = ".\output"
if (-not (Test-Path -Path $outputDir)) {
    New-Item -ItemType Directory -Path $outputDir | Out-Null
    Write-Host "Создана папка $outputDir"
}


$compiler = "g++"
$cppFiles = ".\main.cpp", ".\task.cpp"
$outputFile = ".\output\main.exe"
$options = "-Wall", "-Wextra", "-g3", "-I.", "-fexec-charset=UTF-8"

Write-Host "Компиляция проекта..." -ForegroundColor Green
& $compiler $options $cppFiles -o $outputFile

# Проверяем успешность компиляции
if ($LASTEXITCODE -eq 0) {
    Write-Host "Запуск программы..." -ForegroundColor Yellow
    & $outputFile
} else {
    Write-Host "Ошибка компиляции!" -ForegroundColor Red
}
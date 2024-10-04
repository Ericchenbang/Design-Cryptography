
function generateHiddenMessage() {
    let originalText = document.getElementById('originalText').innerText;
    let hiddenMessage = document.getElementById('hiddenMessage').innerText;

    let hideOption = document.querySelector('input[name="hideOption"]:checked').value;

    let resultHTML = "";
    let hiddenIndex = 0;

    for (let i = 0; i < originalText.length; i++) {
        let currentChar = originalText[i];
                
        if (hiddenIndex < hiddenMessage.length && currentChar.toLowerCase() === hiddenMessage[hiddenIndex].toLowerCase()) {
            let spanClass = '';
            if (hideOption === 'bold') {
                spanClass = 'boldChange';
            } else if (hideOption === 'font') {
                spanClass = 'fontChange';
            } else if (hideOption === 'size') {
                spanClass = 'sizeChange';
            } else if (hideOption === 'color') {
                spanClass = 'colorChange';
            } else if (hideOption === 'margin') {
                spanClass = 'marginChange';
            }

            resultHTML += `<span class="${spanClass}">${currentChar}</span>`;
            hiddenIndex++;
        } else {
            resultHTML += currentChar;
        }
    }

    if (hideOption === 'bold') {
        resultHTML += '.';
    } else if (hideOption === 'font') {
        resultHTML += '~';
    } else if (hideOption === 'size') {
        resultHTML += '!';
    } else if (hideOption === 'color') {
        resultHTML += '_';
    } else if (hideOption === 'margin') {
        resultHTML += '\'';
    }

    document.getElementById('result').innerHTML = resultHTML;
}

/*function copyResult() {
    const resultText = document.querySelector('result');
    resultText.select();

    try {
        document.execCommand('copy');
        alert("結果已成功複製！");
    } catch (err) {
        alert("複製失敗！");
    }

}*/
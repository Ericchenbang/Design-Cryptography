function extractHiddenMessage() {
            let receivedText = document.getElementById('receivedText').innerHTML;

            let lastChar = receivedText.trim().slice(-1);

            let hiddenMessage = '';

            let styleType = '';
            if (lastChar === '.') {
                styleType = 'font-weight: bold;';
            } else if (lastChar === '~') {
                styleType = 'font-family: Arial, Helvetica, sans-serif;';
            } else if (lastChar === '!') {
                styleType = 'font-size: 17.5px;';
            } else if (lastChar === '_') {
                styleType = 'color: rgb(25, 25, 48);';
            } else if(lastChar === '\'') {
                styleType = 'margin: 0.1px;';  
            } else {
                hiddenMessage = "There is no hidden Message!";
            }


            let parser = new DOMParser();
            let doc = parser.parseFromString(receivedText, 'text/html');
            let spans = doc.querySelectorAll('span');
            
            spans.forEach(span => {
                if (span.getAttribute('style') === styleType) {
                    hiddenMessage += span.textContent;
                }
            });

            document.getElementById('hiddenMessage').textContent = hiddenMessage;
        }
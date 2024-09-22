function extractHiddenMessage() {
            let receivedText = document.getElementById('receivedText').innerHTML;

            let lastChar = receivedText.trim().slice(-1);

            let styleType = '';
            if (lastChar === '.') {
                styleType = 'font-weight: bold;';
            } else if (lastChar === '~') {
                styleType = 'font-family: Arial, Helvetica, sans-serif;';
            } else if (lastChar === '!') {
                styleType = 'font-size: 17.5px;';
            }

            let hiddenMessage = '';
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
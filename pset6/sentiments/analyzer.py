import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.positivesset = set()
        file = open(positives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.positivesset.add(line.rstrip("\n"))
        file.close()
        
        self.negativesset = set()
        file = open(negatives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.negativesset.add(line.rstrip("\n"))
        file.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        sum = 0
        for word in tokens:
            if word.lower() in self.positivesset:
                sum += 1
            elif word.lower() in self.negativesset:
                sum -= 1
            else:
                continue
        
        return sum
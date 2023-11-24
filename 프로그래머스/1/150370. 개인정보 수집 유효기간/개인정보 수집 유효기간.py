def convert_day(date_format:str):
    today_ = date_format.split('.')
    # month
    day = (int(today_[1])-1) * 28 + int(today_[2])
    today_ = (int(today_[0])-2000)*28*12 + day
    # today -> day converting
    return today_

def solution(today, terms, privacies):
    today_date = convert_day(today)
    term_dict = dict()
    for term in terms:
        alphabet, numb = term.split(' ')
        term_dict[alphabet] = int(numb) * 28
    
    date_list = list()
    for privacy in privacies:
        my_date, alphabet = privacy.split(' ')
        date_list.append([convert_day(my_date), term_dict[alphabet]])   

    answer = []
    for i in range(len(date_list)):
        if(date_list[i][0]+date_list[i][1] <= today_date):
            answer.append(i+1)
    # print(date_list)
    # print(today_date)
    return answer
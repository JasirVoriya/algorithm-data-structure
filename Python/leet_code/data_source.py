import json
import requests


def get_leet_code_questions_info(url: str, headers: dict, data: dict):

    res_json = requests.post(url=url, headers=headers,
                             data=json.dumps(data)).json()
    AC_questions = res_json['data']['userProfileUserQuestionProgress']['numAcceptedQuestions']
    failed_questions = res_json['data']['userProfileUserQuestionProgress']['numFailedQuestions']
    untouched_questions = res_json['data']['userProfileUserQuestionProgress']['numUntouchedQuestions']
    ans = dict()
    ans['AC'] = dict()
    for questions in AC_questions:
        ans['AC'][questions['difficulty']] = questions['count']
    ans['WA'] = dict()
    for questions in failed_questions:
        ans['WA'][questions['difficulty']] = questions['count']
    ans['NEW'] = dict()
    for questions in untouched_questions:
        ans['NEW'][questions['difficulty']] = questions['count']
    return ans


def get_leet_code_user_info(url: str, headers: dict, data: dict):
    res_json = requests.post(url=url, headers=headers,
                             data=json.dumps(data)).json()

    nickname = res_json['data']['userProfilePublicProfile']['profile']['realName']
    avatar_url = res_json['data']['userProfilePublicProfile']['profile']['userAvatar']
    return {'NICKNAME': nickname, 'AVATAR_URL': avatar_url}


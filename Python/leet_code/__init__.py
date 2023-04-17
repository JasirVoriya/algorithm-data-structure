# -*- coding: utf-8 -*-

from .config import Config

from .data_source import get_leet_code_questions_info, get_leet_code_user_info


def get_all(user_space: str) -> dict:
    config = Config(user_space=user_space)

    res = get_leet_code_user_info(
        url=config.url, headers=config.headers, data=config.data['userPublicProfile'])
    res.update(get_leet_code_questions_info(url=config.url,
               headers=config.headers, data=config.data['userQuestionProgress']))
    return res

